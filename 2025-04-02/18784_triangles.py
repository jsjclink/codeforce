from collections import defaultdict

n = int(input())

points = []
xfix_counts = defaultdict(int) # xfix_counts[x]: num of (x, *)
yfix_counts = defaultdict(int) # yfix_counts[y]: num of (*, y)
xfix_sums = defaultdict(int) # xfix_sums[x]: sum of y (x, *)
yfix_sums = defaultdict(int) # yfix_counts[y]: sum of x (*, y)

for _ in range(n):
    x, y = tuple(map(int, input().split()))
    points.append((x, y))
    xfix_counts[x] += 1
    yfix_counts[y] += 1
    xfix_sums[x] += y
    yfix_sums[y] += x

points_xsort = sorted(points) # x fix
points_ysort = sorted(points, key=lambda x: (x[1], x[0])) # y fix

side_sums_x = defaultdict(int)
side_sums_y = defaultdict(int)

dx, i = -1, 0
for x, y in points_xsort:
    if dx != x:
        i = 0
    
    