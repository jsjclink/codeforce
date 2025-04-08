for _ in range(int(input())):
    x, k = tuple(map(int, input().split()))
    if x > 1 and k > 1:
        print("NO")
        continue
    
    s = ""
    while k > 0:
        s += str(x)
        k -= 1
    x = int(s)
    if x == 1:
        print("NO")
        continue
    if x == 2:
        print("YES")
        continue
    if x%2 == 0:
        print("NO")
        continue
    for i in range(3, int(x ** 0.5) + 1, 2):
        if x % i == 0:
            print("NO")
            break
    else:
        print("YES")
     