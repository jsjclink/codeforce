for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input().split()))
    min_a = min(a_list)
    max_a = max(a_list)
    
    print(max_a - min_a)