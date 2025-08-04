MOD = 998244353
def fast_pow(b):
    a, b = 2, int(b)
    res = 1
    while b > 0:
        if b % 2 == 1:
            res = res * a % MOD
        a = a * a % MOD
        b //= 2
    return res

def solve():
    n = int(input())
    p_list = list(map(fast_pow, input().split()))
    q_list = list(map(fast_pow, input().split()))
        
    p_max = [(p_list[0], 0)]
    q_max = [(q_list[0], 0)]
    for i in range(1, n):
        if p_max[i-1][0] < p_list[i]:
            p_max.append((p_list[i], i))
        else:
            p_max.append(p_max[i-1])
        if q_max[i-1][0] < q_list[i]:
            q_max.append((q_list[i], i))
        else:
            q_max.append(q_max[i-1])
    
    for i in range(n):
        case1 = (p_max[i][0] + q_list[i - p_max[i][1]]) % MOD
        case2 = (q_max[i][0] + p_list[i - q_max[i][1]]) % MOD
        print(max(case1, case2), end=" ")
    
    print()
    
for _ in range(int(input())):
    solve()
