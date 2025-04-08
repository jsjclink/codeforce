for _ in range(int(input())):
    n, k, x = tuple(map(int, input().split()))
    a_lst = list(map(int, input().split()))

    a_sum = sum(a_lst)
    iter = x // a_sum
    rem = x % a_sum
    if iter > k or (iter == k and rem != 0):
        print(0)
        continue
    if rem == 0: # 제발 엣지케이스 잘 생각하기,,
        print(n*k - iter*n + 1)
        continue
    cur_sum = a_sum * iter
    for i in range(n):
        cur_sum += a_lst[n-1-i]
        if cur_sum >= x:
            break
    if cur_sum >= x:
        print(n*k - iter*n - i)
    else:
        print(0)