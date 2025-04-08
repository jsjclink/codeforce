for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input().split()))
    zeros = 0
    ones = 0
    twos = 0
    threes = 0
    fives = 0
    for i, a in enumerate(a_list):
        match a:
            case 0:
                zeros += 1
            case 1:
                ones += 1
            case 2:
                twos += 1
            case 3:
                threes += 1
            case 5:
                fives += 1
        if zeros >= 3 and ones >= 1 and twos >= 2 and threes >= 1 and fives >= 1:
            print(i + 1)
            break
    else:
        print(0)