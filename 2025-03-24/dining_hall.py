from __future__ import annotations
import heapq


class TableSeat:
    DXY_TO_DIST = {
        (1, 1): 2,
        (1, 2): 3,
        (2, 1): 3,
        (2, 2): 6,
    }

    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def dist(self) -> int:
        return (self.x // 3 + self.y // 3) * 3 + TableSeat.DXY_TO_DIST[
            (self.x % 3, self.y % 3)
        ]

    def __lt__(self, other: TableSeat):
        if self.dist() != other.dist():
            return self.dist() < other.dist()
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

    def __eq__(self, other: TableSeat) -> bool:
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

    def next_table_seats0(self, occupied: set[TableSeat]) -> list[TableSeat]:
        first_x = self.x // 3 * 3 + 1
        first_y = self.y // 3 * 3 + 1
        return [
            table_seat
            for table_seat in [
                TableSeat(first_x + 3, first_y),
                TableSeat(first_x, first_y + 3),
            ]
            if table_seat not in occupied
        ]

    def next_table_seats1(self, occupied: set[TableSeat]) -> list[TableSeat]:
        base_x = self.x // 3 * 3
        base_y = self.y // 3 * 3
        return [
            table
            for dx, dy in TableSeat.DXY_TO_DIST.keys()
            if (table := TableSeat(base_x + dx, base_y + dy)) not in occupied
        ]


q = int(input())
for _ in range(q):
    try:
        n = int(input())
        t_list = list(map(int, input().split()))
        table_heap0 = [TableSeat(1, 1)]
        table_heap1 = [TableSeat(1, 1)]
        occupied_table = set()

        for t in t_list:
            if t == 0:
                table_seat = heapq.heappop(table_heap0)
                while table_seat in occupied_table:
                    table_seat = heapq.heappop(table_heap0)
            else:
                table_seat = heapq.heappop(table_heap1)
                while table_seat in occupied_table:
                    table_seat = heapq.heappop(table_heap1)

            occupied_table.add(table_seat)
            for next_table_seat in table_seat.next_table_seats0(occupied_table):
                heapq.heappush(table_heap0, next_table_seat)
                heapq.heappush(table_heap1, next_table_seat)
            for next_table_seat in table_seat.next_table_seats1(occupied_table):
                heapq.heappush(table_heap1, next_table_seat)
            print(f"{table_seat.x} {table_seat.y}")
    except Exception as e:
        print(repr(e))
