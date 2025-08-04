def solve():
    a, b, c, d = map(int, input().split())
    g_hp = min(a, c)
    f_hp = min(b, d)
    
    if g_hp >= f_hp:
        print("Gellyfish")
    else:
        print("Flower")

for _ in range(int(input())):
    solve()
