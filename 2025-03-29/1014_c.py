for _ in range(int(input())):
    n = int(input())
    a_list = list(map(int, input().split()))
    odds = []
    evens = []
    
    for a in a_list:
        if a % 2 == 0:
            evens.append(a)
        else:
            odds.append(a)
    
    if len(odds) == 0:
        print(max(evens))
        continue
    if len(evens) == 0:
        print(max(odds))
        continue
    
    m = evens.pop()
    print(m + sum(odds) - len(odds) + 1 + sum(evens))


    


# for _ in range(int(input())):
#     n = int(input())
#     a_list = list(map(int, input().split()))
#     odds = []
#     evens = []
    
#     for a in a_list:
#         if a % 2 == 0:
#             evens.append(-a)
#         else:
#             odds.append(-a)

#     if len(odds) == 0:
#         print(-min(evens))
#         continue
#     if len(evens) == 0:
#         print(-min(odds))
#         continue
            
#     heapq.heapify(odds)
#     heapq.heapify(evens)

#     om = -heapq.heappop(odds)
#     em = -heapq.heappop(evens)
#     if om >= em:
#         heapq.heappush(evens, -em)
#         m = om
#     else:
#         heapq.heappush(odds, -om)
#         m = em

#     while True:
#         if m % 2 == 0:
#             if len(odds) == 0:
#                 break
#             om = -heapq.heappop(odds)
#             om -= 1
#             m += 1
#             if om > 0:
#                 heapq.heappush(evens, -om)        
#         else:
#             if len(evens) == 0:
#                 break
#             em = -heapq.heappop(evens)
#             em -= 1
#             m += 1
#             if em > 0:
#                 heapq.heappush(odds, -em)
#     print(m)