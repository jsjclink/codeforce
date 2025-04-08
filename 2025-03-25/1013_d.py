for _ in range(int(input())):
    n, m, k = tuple(map(int, input().split()))
    l, r = 1, m
    while l <= r:
        i = (l + r) // 2
        
        i_table_count = (m + 1) // (i + 1)
        rem = (m + 1) % (i + 1) - 1
        table_count = i_table_count * i + (rem if rem >= 0 else 0)
        if table_count * n < k:
            l = i + 1
        else:
            r = i - 1
    print(l)
