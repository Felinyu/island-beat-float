import io, re, yaml
p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()
m = re.search(r"// ==WindhawkModSettings==\s*/\*(.*?)\*/\s*// ==/WindhawkModSettings==", t, re.S)
data = yaml.safe_load(m.group(1))
print("settings top-level:", type(data).__name__, "keys:", [list(x.keys())[0] if isinstance(x, dict) else x for x in data])
inner = data[0]["Main"]
print("settings count:", len(inner))
print("keys:", [list(x.keys())[0] for x in inner])
