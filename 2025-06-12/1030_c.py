import heapq

def next_op_num(a):
    original_a = a
    least_zero_idx = None
    cur_idx = 0
    while a > 0:
        if a % 2 == 0:
            least_zero_idx = cur_idx
            break
        a = a // 2
        cur_idx += 1
    return 2 ** least_zero_idx if least_zero_idx is not None else original_a + 1

def beauty(a):
    cnt = 0
    while a > 0:
        if a % 2 == 1:
            cnt += 1
        a = a // 2
    return cnt            

def solve():
    n, k = map(int, input().split())
    a_list = list(map(int, input().split()))
    
    op_lst = []
    
    beauty_sum = 0
    for a in a_list:
        op_cnt = next_op_num(a)
        op_lst.append((op_cnt, a))
        beauty_sum += beauty(a)
    heapq.heapify(op_lst)
    
    while k > 0 and op_lst:
        op_cnt, a = heapq.heappop(op_lst)
        if k - op_cnt < 0:
            break
        
        beauty_sum += 1
        k -= op_cnt
        new_a = a + op_cnt
        new_op_cnt = next_op_num(new_a)
        heapq.heappush(op_lst, (new_op_cnt, new_a))
    print(beauty_sum)

for _ in range(int(input())):
    solve()
