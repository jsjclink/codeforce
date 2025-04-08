for _ in range(int(input())):
    n, m, d = tuple(map(int, input().split()))
    mountain = []
    for i in range(n):
        mountain.append([x == "X" for x in list(input())])
    
    dp = [[0 for _ in range(m)] for _ in range(n)]
    
    for r in range(n):
        for c in range(m):
            