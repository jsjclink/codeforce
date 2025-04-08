for _ in range(int(input())):
    n, x = tuple(map(int, input().split()))
    a_list = sorted(list(map(int, input().split())))
    count = 0
    member_count = 1
    for a in reversed(a_list):
        if a >= x:
            count += 1
        elif member_count * a < x:
            member_count += 1
        else:
            count += 1
            member_count = 1
    print(count)
        