def binary(A, left, right, x):
    if left > right:
        return -1
    mid = (left + right) // 2
    if x == A[mid]:
        return mid
    elif x < A[mid]:
        return binary(A, left, mid - 1, x)
    else:
        return binary(A, mid + 1, right, x)

if __name__ == '__main__':
    A = [2, 5, 6, 8, 9, 10]
    key = 5
    (left, right) = (0, len(A) - 1)
    index = binary(A, left, right, key)

    if index != -1:
        print("Element found at index ", index)
    else:
        print("Element not found in array")
