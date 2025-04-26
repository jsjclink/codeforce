n = int(input())
a_list = list(map(int, input().split()))

m = max(a_list)

price = 0
for h in reversed(range(1, m+1)):
    count = 0
    for i in range(n):
        if a_list[i] == h:
            a_list[i] -= 1
            count += 1
        elif count > 0:
            trip, count = count // 3, count % 3
            doub, count = count // 2, count % 2
            one, count = count // 1, count % 1
            price += trip * 7 + doub * 5 + one * 3
    if count > 0:
        trip, count = count // 3, count % 3
        doub, count = count // 2, count % 2
        one, count = count // 1, count % 1
        price += trip * 7 + doub * 5 + one * 3
print(price)
            