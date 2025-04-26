def find_insert_idx_v1(arr, num):
    if len(arr) > 0 and arr[-1] < num:
        return len(arr)
    
    l, r = 0, len(arr) - 1
    while l < r:
        mid = (l + r) // 2
        if arr[mid] == num:
            return mid
        elif arr[mid] < num:
            l = mid + 1
        else:
            r = mid
    return l

def find_insert_idx(arr, num):
    l, r = 0, len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] < num:
            l = mid + 1
        else:
            r = mid
    return l
