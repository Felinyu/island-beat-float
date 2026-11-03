import io
p = r"C:\dsh\work\island-fork\cleanup3.py"
c = io.open(p, encoding="utf-8").read()
old = '''start = None
for i, line in enumerate(lines):
    if line.startswith("void ApplyOptimisticFavoriteToggle(") or line.startswith("void ApplyOptimisticFavoriteToggle ("):
        start = i
        break
assert start is not None, "ApplyOptimisticFavoriteToggle not found"
depth = 0
seen = False
end = None
for j in range(start, len(lines)):
    depth += lines[j].count("{") - lines[j].count("}")
    if "{" in lines[j]:
        seen = True
    if seen and depth == 0:
        end = j
        break
assert end is not None
print("removing lines", start + 1, "-", end + 1, ":", lines[start])
del lines[start:end + 1]'''
new = '''start = None
for i, line in enumerate(lines):
    if line.startswith("void ApplyOptimisticFavoriteToggle(") and ";" not in line.rstrip()[-2:]:
        start = i
        break
    if line.startswith("void ApplyOptimisticFavoriteToggle(") and not line.rstrip().endswith(";"):
        start = i
        break
assert start is not None, "ApplyOptimisticFavoriteToggle definition not found"
depth = 0
seen = False
end = None
for j in range(start, len(lines)):
    depth += lines[j].count("{") - lines[j].count("}")
    if "{" in lines[j]:
        seen = True
    if seen and depth == 0:
        end = j
        break
assert end is not None
print("removing definition lines", start + 1, "-", end + 1, ":", lines[start].strip())
del lines[start:end + 1]
# remove its forward declaration if present
decls = [i for i, line in enumerate(lines) if line.strip() == "void ApplyOptimisticFavoriteToggle();"]
for i in reversed(decls):
    print("removing declaration at line", i + 1)
    del lines[i]'''
if old not in c:
    raise SystemExit("old block not found")
c = c.replace(old, new)
io.open(p, "w", encoding="utf-8").write(c)
print("cleanup3.py patched")
