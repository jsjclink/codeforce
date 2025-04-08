facs = [1]
curr = 1
for i in range(1, 5*10**5+1):
    curr = curr*i%998244353
    facs.append(curr)

for _ in range(int(input())):
    c_list = list(map(int, input().split()))
    c_sum = sum(c_list)
