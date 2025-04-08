for _ in range(int(input())):
    n = int(input())
    count = 0
    while n % 10 == 0:
        n = n // 10
        count += 1
    for d in str(n)[:-1]:
        if d == '0':
            continue
        count += 1
    print(count)