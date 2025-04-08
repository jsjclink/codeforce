for _ in range(int(input())):
    n = int(input())
    p_list = list(map(int, input().split()))
    d_lst = list(map(int, input().split()))
    p_to_idx = {p: i for i, p in enumerate(p_list)}

    op_applied = set()
    count = 0
    count_lst = []
    for d in d_lst:
        op_idx = d-1
        if op_idx in op_applied:
            count_lst.append(count)
            continue
        op_applied.add(op_idx)
        count += 1
        while True:
            op_idx = p_list[op_idx] - 1
            if op_idx in op_applied:
                break
            op_applied.add(op_idx)
            count += 1
        count_lst.append(count)

    print(" ".join(map(str, count_lst)))