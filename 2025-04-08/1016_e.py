def mex(arr):
    s = set(arr)
    i = 0
    while i in s:
        i += 1
    return i

def find_bonus_mex(bonus, prev_mex, r, a_list):
    


for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    a_list = list(map(int, input().split()))
    
    cur_mex = n//k
    bonus = n%k
    l, r = 0, cur_mex
    while True:
        tmp_mex = mex(a_list[l:r])
        if tmp_mex < cur_mex:
            prev_r = r
            tmp_r = r
            tmp_bonus = bonus
            while tmp_bonus > 0:
                tmp_r += 1
                tmp_bonus -= 1
                bonus_mex = mex(a_list[l:r])
                if bonus_mex > tmp_mex:
                    tmp_r