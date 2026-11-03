import io, re, os

base = r"C:\dsh\work\island-fork"
src = os.path.join(base, "island-fork.wh.cpp")
warnpath = os.path.join(base, "warnings.txt")
t = io.open(src, encoding="utf-8", errors="replace").read()
lines = t.split("\n")

warn = io.open(warnpath, encoding="utf-8", errors="replace").read()
unused = []
for m in re.finditer(r"island-fork\.wh\.cpp:(\d+):\d+: warning: unused (function|variable) '([^']+)'", warn):
    unused.append((int(m.group(1)), m.group(2), m.group(3)))
print("unused symbols:", len(unused))

def find_close(start):
    depth = 0
    seen = False
    for i in range(start, len(lines)):
        depth += lines[i].count("{") - lines[i].count("}")
        if "{" in lines[i]:
            seen = True
        if seen and depth == 0:
            return i
    return -1

deletions = []  # (start, end, label) inclusive 0-based

for ln, kind, name in unused:
    idx = ln - 1
    if kind == "variable":
        deletions.append((idx, idx, "unused var " + name))
        continue
    j = idx
    while j < len(lines) and "{" not in lines[j]:
        j += 1
    end = find_close(j)
    if end < 0:
        print("WARN: could not find end for", name); continue
    deletions.append((idx, end, "unused fn " + name))

# IslandDebugAppend function
for i, line in enumerate(lines):
    if line.startswith("void IslandDebugAppend("):
        end = find_close(i)
        deletions.append((i, end, "IslandDebugAppend"))
        break

# TEMP DIAG block
for i, line in enumerate(lines):
    if "// TEMP DIAG" in line:
        end = None
        for k in range(i, min(i + 40, len(lines))):
            if "IslandDebugAppend(buf);" in lines[k]:
                m = k
                while m < len(lines) and lines[m].strip() != "}":
                    m += 1
                end = m
                break
        if end is not None:
            deletions.append((i, end, "TEMP DIAG block"))
        break

# layoutChanged debug lines
for i, line in enumerate(lines):
    if "wchar_t buf[256];" in line and i + 3 < len(lines) and "IslandDebugAppend(buf);" in lines[i + 2]:
        deletions.append((i, i + 2, "layoutChanged debug"))
        break

# #if 0 blocks
i = 0
while i < len(lines):
    if lines[i].strip().startswith("#if 0"):
        depth = 0
        end = i
        for k in range(i, len(lines)):
            s = lines[k].strip()
            if s.startswith("#if"):
                depth += 1
            elif s.startswith("#endif"):
                depth -= 1
                if depth == 0:
                    end = k
                    break
        deletions.append((i, end, "#if 0 block @%d" % (i + 1)))
        i = end + 1
        continue
    i += 1

deletions.sort(key=lambda d: d[0])
print("deletions:", len(deletions))
merged = []
for start, end, label in deletions:
    if merged and start <= merged[-1][1] + 1:
        merged[-1] = (merged[-1][0], max(merged[-1][1], end), merged[-1][2] + "; " + label)
    else:
        merged.append((start, end, label))

# build new content
removed_lines = sum(e - s + 1 for s, e, _ in merged)
print("total lines to remove:", removed_lines)
out = []
idx = 0
mergeset = {s: e for s, e, _ in merged}
while idx < len(lines):
    if idx in mergeset:
        idx = mergeset[idx] + 1
        continue
    out.append(lines[idx])
    idx += 1

# collapse 3+ blank lines
cleaned = []
blank = 0
for line in out:
    if line.strip() == "":
        blank += 1
        if blank > 2:
            continue
    else:
        blank = 0
    cleaned.append(line)

result = "\n".join(cleaned)
io.open(src, "w", encoding="utf-8", newline="\n").write(result)
print("new lines:", len(cleaned), "new bytes:", len(result.encode("utf-8")))
for s, e, label in merged:
    print("removed %d-%d: %s" % (s + 1, e + 1, label))
