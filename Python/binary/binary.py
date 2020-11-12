def binary(A, x):
    (left, right) = (0, len(A) - 1)
    while left <= right:
        mid = (left + right) // 2

        if x == A[mid]:
            return mid
        elif x < A[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1

if __name__ == '__main__':
    A = [2, 5, 8, 9, 10]
    key = 5

    index = binary(A, key)

    if index != -1:
        print("Element found at index ", index)
    else:
        print("Element not found in array")
