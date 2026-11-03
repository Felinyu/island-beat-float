import io
p = r"C:\dsh\work\island-fork\island-fork.wh.cpp"
t = io.open(p, encoding="utf-8", errors="replace").read()
old = """            wchar_t buf[256];
            swprintf_s(buf, 256, L"layoutChanged taskbarH=%.1f compactW=%.1f",
                       g_layout.taskbarHeightDip, g_layout.compactWidth);
            IslandDebugAppend(buf);
"""
if old not in t:
    raise SystemExit("layoutChanged debug block not found")
t = t.replace(old, "", 1)
io.open(p, "w", encoding="utf-8", newline="\n").write(t)
print("removed layoutChanged debug block")
