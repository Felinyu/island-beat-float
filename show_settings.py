import io, re
p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()
s = re.search(r"// ==WindhawkModSettings==\s*/\*(.*?)\*/\s*// ==/WindhawkModSettings==", t, re.S)
print("===== SETTINGS YAML =====")
print(s.group(1))
