def solve():
    n, k = map(int, input().split())
    res = ""
    for i in range(n):
        if i < k:
            res += "1"
        else:
            res += "0"
    print(res)

for _ in range(int(input())):
    solve()
