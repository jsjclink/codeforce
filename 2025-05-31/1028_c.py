def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def calc_gcd(a_list):
    g = a_list[0]
    for i in range(1, len(a_list)):
        g = gcd(g, a_list[i])
    return g

def solve():
    n = int(input())
    a_list = list(map(int, input().split()))
    
    g = calc_gcd(a_list)
    g_count = a_list.count(g)

    if g_count == 0:
        a_set = set(a_list)
        exclude_set = set()
        essential_cnt = 0
        for i in range(n):
            exclude_set.add(a_list[i])
            if calc_gcd(list(a_set - exclude_set)) != g:
                exclude_set.remove(a_list[i])
                essential_cnt += 1
        print(essential_cnt-1+n-1)
    else:
        print(n-g_count)

for _ in range(int(input())):
    solve()
