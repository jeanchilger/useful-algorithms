def quicksort(arr, first, last):
    """
    sorts an array in increasing order
    """
    if first < last:
        p = partition(arr, first, last)

        quicksort(arr, first, p - 1)
        quicksort(arr, p + 1, last)

def partition(arr, first, last):
    """
    returns the index of the pivot
    before return, the pivot is set to its correct position
    """
    pivot = first
    low = first + 1
    high = last

    while low <= high:
        if arr[low] <= arr[pivot]:
            low += 1
        else:
            if arr[high] >= arr[pivot]:
                high -= 1
            else:
                temp = arr[low]
                arr[low] = arr[high]
                arr[high] = temp

    temp = arr[pivot]
    arr[pivot] = arr[high]
    arr[high] = temp

    return high

# tests the algorithm
a = [54, 26, 93, 17, 77, 31, 44, 55, 20]
quicksort(a, 0, len(a)-1)
print(a)
