def find_d(n, x, y):
    rel_pos_list = []
    for i in reversed(range(n)):
        div = 2 ** i
        xq = x // div
        xr = x % div
        yq = y // div
        yr = y % div
        x, y = xr, yr
        rel_pos_list.append((xq, yq))
    d = 0
    for i, rel_pos in enumerate(reversed(rel_pos_list)):
        if rel_pos == (0, 0):
            d += 0
        if rel_pos == (1, 1):
            d += 1 * (2 ** (2*i))
        if rel_pos == (1, 0):
            d += 2 * (2 ** (2*i))
        if rel_pos == (0, 1):
            d += 3 * (2 ** (2*i))
    return d + 1

def find_cord(n, d):
    dq_list = []
    for i in reversed(range(n)):
        div = (2 ** (2*i))
        dq = d // div
        dr = d % div
        d = dr
        dq_list.append(dq)
    x, y = 0, 0
    for i, dq in enumerate(reversed(dq_list)):
        if dq == 0:
            pass
        if dq == 1:
            x += 1 * (2 ** i)
            y += 1 * (2 ** i)
        if dq == 2:
            x += 1 * (2 ** i)
        if dq == 3:
            y += 1 * (2 ** i)
    return f"{x+1} {y+1}"


for _ in range(int(input())):
    n = int(input())
    for _ in range(int(input())):
        inp = input().split()
        if inp[0] == '->':
            x, y = int(inp[1]), int(inp[2])
            print(find_d(n, x-1, y-1))
        elif inp[0] == '<-':
            d = int(inp[1])
            print(find_cord(n, d-1))
        else:
            raise