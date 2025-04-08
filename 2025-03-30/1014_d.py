TIL = set(["T", "I", "L"])

for _ in range(int(input())):
    n = int(input())
    tils = list(input())
    counts = {"T": 0, "I": 0, "L": 0}
    tilcomb_pos = {}

    for i in range(n):
        counts[tils[i]] += 1
        if  i == n-1 or tils[i] == tils[i+1]:
            continue
        tilcomb_pos[(tils[i], tils[i+1])] = i
    
    a = max(counts, key=counts.get)
    b, c = tuple(TIL - set(a))
    if counts[b] < counts[c]:
        b, c = c, b
    
    if counts[a] == counts[b] and counts[b] == counts[c]:
        print(0)
        continue
    # a....a -> fail
    if counts[b]+counts[c] == 0:
        print(-1)
        continue
    
    print_lst = []
    # a, b, c -> a+b-c, b, b
    for comb in [(b, c), (c, b), (b, a), (a, b)]:
        if comb in tilcomb_pos:
            base_i = tilcomb_pos[comb]
            inc = comb[1] == b
            break
    for i in range(counts[b] - counts[c]):
        if inc:
            print_lst.append(base_i + 2*i + 1)
            print_lst.append(base_i + 2*i + 1 + 1)
        else:
            print_lst.append(base_i + 1)
            print_lst.append(base_i + 1)

    # a+b-c, b, b -> a+b-c, a+b-c, a+b-c
    prev_base_i, prev_comb = base_i, comb
    for comb in [(a, c), (c, a), (a, b), (b, a)]:
        if comb in tilcomb_pos:
            base_i = tilcomb_pos[comb]
            inc = comb[1] == a
            break
    if base_i > prev_base_i:
        base_i += (counts[b] - counts[c])
    elif comb == (a, b) and prev_comb == (a, b):
        base_i += (counts[b] - counts[c])
    for i in range(counts[a] - counts[c]):
        if inc:
            print_lst.append(base_i + 2*i + 1)
            print_lst.append(base_i + 2*i + 1 + 1)
        else:
            print_lst.append(base_i + 1)
            print_lst.append(base_i + 1)

    print(len(print_lst))
    for l in print_lst:
        print(l)