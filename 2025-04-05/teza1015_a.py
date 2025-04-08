for _ in range(int(input())):
    n = int(input())
    if n % 2 == 0:
        print(-1)
        continue
    
    print_list = [n]
    for i in range(1, n):
        print_list.append(i)
    print(" ".join(map(str, print_list)))