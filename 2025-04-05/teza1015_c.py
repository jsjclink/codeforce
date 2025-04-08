for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input().split()))
    b_list = (list(map(int, input().split())))[::-1]
    
    if a_list == b_list:
        print(0)
        continue
    
    print_list = []
    if n%2 == 1 and a_list[n//2] != b_list[n//2]:
        for i in range(n):
            if a_list[i] == b_list[n-1-i]:
                a_list[i], a_list[n//2] = a_list[n//2], a_list[i]
                b_list[n-1-i], b_list[n//2] = b_list[n//2], b_list[n-1-i]
                print_list.append(f"{i+1} {n//2+1}")
                break
        else:
            print(-1)
            continue
    
    a_to_b, b_to_a = {}, {}
    for i in range(n):
        a_to_b[a_list[i]] = b_list[n-1-i]
        b_to_a[b_list[i]] = a_list[n-1-i]
    if a_to_b != b_to_a:
        print(-1)
        continue

    a_to_idx = {a: i for i, a in enumerate(a_list)}
    for i in range(n//2):
        j = a_to_idx[b_list[i]]
        if i == j:
            continue
        a_list[i], a_list[j] = a_list[j], a_list[i]
        b_list[n-1-i], b_list[n-1-j] = b_list[n-1-j], b_list[n-1-i]
        a_to_idx[a_list[i]], a_to_idx[a_list[j]] = i, j
        print_list.append(f"{i+1} {j+1}")

    if not a_list == b_list:
        print(-1)
    else:
        print(len(print_list))
        for p in print_list:
            print(p)
    