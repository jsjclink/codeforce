n = int(input())
a_list = list(map(int, input().split()))

def find_insert_idx(arr, num):
    if len(arr) > 0 and arr[-1] < num:
        return len(arr)
    
    l, r = 0, len(arr) - 1
    while l < r:
        mid = (l + r) // 2
        if arr[mid] == num:
            return mid
        elif arr[mid] < num:
            l = mid + 1
        else:
            r = mid
    return l

link = [-1 for _ in range(n)]
dp = [] # dp[i]: i+1 길이를 가지는 inc seq중 가장 작은 끝값
num_to_idx = {}

for i, a in enumerate(a_list):
    idx = find_insert_idx(dp, a)
    if idx == len(dp):
        if len(dp) > 0:
            link[i] = num_to_idx[dp[-1]]
        dp.append(a)    
    else:
        if idx > 0:
            link[i] = num_to_idx[dp[idx-1]]
        dp[idx] = a
    num_to_idx[a] = i

cur_idx = num_to_idx[dp[-1]]
ans = [a_list[cur_idx]]
while True:
    cur_idx = link[cur_idx]
    if cur_idx < 0:
        break
    ans.append(a_list[cur_idx])
print(len(ans))
print(' '.join(map(str, list(reversed(ans)))))