import io, re, json
p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()
lines = t.split("\n")
print("total lines:", len(lines))
print("bytes:", len(t.encode("utf-8")))

# metadata block
m = re.search(r"// ==WindhawkMod==(.*?)// ==/WindhawkMod==", t, re.S)
meta = m.group(1)
for line in meta.strip().split("\n"):
    print("META:", line.strip())
# readme length
r = re.search(r"// ==WindhawkModReadme==\s*/\*(.*?)\*/\s*// ==/WindhawkModReadme==", t, re.S)
print("readme chars:", len(r.group(1)) if r else "none")
s = re.search(r"// ==WindhawkModSettings==\s*/\*(.*?)\*/\s*// ==/WindhawkModSettings==", t, re.S)
print("settings chars:", len(s.group(1)) if s else "none")

# top-level functions (rough)
funcs = re.findall(r"^(?:static\s+)?(?:[A-Za-z_][\w:<>,\s\*&]*?)\s+([A-Za-z_]\w*)\s*\([^;]*\)\s*\{\s*$", t, re.M)
print("function defs (col-0):", len(funcs))
# structs/classes/enums
structs = re.findall(r"^(?:struct|class|enum class|enum)\s+(\w+)", t, re.M)
print("structs/classes/enums:", len(structs), structs[:40])
# section banners
banners = re.findall(r"^//\s*={3,}.*$", t, re.M)
print("section banners:", len(banners))
for b in banners[:40]: print("  ", b.strip())
# #if 0 blocks
for mm in re.finditer(r"#if 0", t):
    ln = t[:mm.start()].count("\n")+1
    print("#if 0 at line", ln)
# settings keys
if s:
    keys = re.findall(r"^-\s*([0-9A-Za-z_-]+):", s.group(1), re.M)
    print("settings keys:", len(keys))
    print("KEYS:", ",".join(keys))
