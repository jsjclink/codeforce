def gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x


for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input().split()))
    min_a = min(a_list)
    a_list.remove(min_a)
    if min_a in a_list:
        print("YES")
        continue
    
    cur_gcd = None
    for a in a_list:
        if a % min_a > 0:
            continue
        if cur_gcd is None:
            cur_gcd = a // min_a
        else:
            cur_gcd = gcd(cur_gcd, a // min_a)

    if cur_gcd == 1:
        print("YES")
    else:
        print("NO")