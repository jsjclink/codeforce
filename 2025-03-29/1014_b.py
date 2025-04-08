for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input()))
    b_list = list(map(int, input()))
    
    ae_count = 0 # num of 1 at even
    ao_count = 0 # num of 1 at odd
    be_count = 0 # num of 0 at even
    bo_count = 0 # num of 0 at odd
    for i, a in enumerate(a_list):
        if a == 0:
            continue
        if i % 2 == 0:
            ae_count += 1
        else:
            ao_count += 1
    for i, b in enumerate(b_list):
        if b == 1:
            continue
        if i % 2 == 0:
            be_count += 1
        else:
            bo_count += 1
    if ae_count <= bo_count and ao_count <= be_count:
        print("YES")
    else:
        print("NO")
            
    
