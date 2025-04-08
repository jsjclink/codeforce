occupied_cell = set()

def next_unoccupied_cell(x, y):
    # x = 3 * q0 + r0
    # y = 3 * q1 + r1
    q0, q1 = x // 3, y // 3
    r0, r1 = x % 3, y % 3
    
    for q2, q3 in [(0, 0), (0, 1), (1, 0)]:
        for r2, r3 in [(1, 1), (1, 2), (2, 1), (2, 2)]:
            x1 = 3 * q2 + q3
            x2 = 3 * q2
        
    
    