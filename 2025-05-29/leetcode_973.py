from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        xy_n_dist_heap = []
        for point in points:
            x, y = point[0], point[1]
            dist = x*x + y*y
            heapq.heappush(xy_n_dist_heap, (-dist, point))
            if len(xy_n_dist_heap) > k:
                heapq.heappop(xy_n_dist_heap)
        return [
            point
            for (_, point) in xy_n_dist_heap
        ]


if __name__ == "__main__":
    points = [[1, 3], [-2, 2]]
    k = 1
    print(Solution().kClosest(points, k))
