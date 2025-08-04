def solve():
    n = int(input())
    
    print(2*n-3)
    
    for i in range(1, n):
        print(i+1, 1, i+1)
        if i > 1:
            print(i+1, 1, i)

for _ in range(int(input())):
    solve()
