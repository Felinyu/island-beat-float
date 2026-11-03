import io
p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
lines = io.open(p, encoding="utf-8").read().split("\n")
# remove leftover tail of MediaThumbFingerprint (return hash; })
assert lines[2137].strip() == "return hash;", lines[2137]
assert lines[2138].strip() == "}", lines[2138]
del lines[2137:2139]
# insert Media state banner before MediaIdentityKey
idx = None
for i, l in enumerate(lines):
    if l.startswith("std::wstring MediaIdentityKey("):
        idx = i
        break
assert idx is not None
lines[idx:idx] = ["", "// ===== Media state model ====="]
io.open(p, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
print("collision fixed, lines:", len(lines))
