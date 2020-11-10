def insertionSort(A):
    for i in range(1, len(A)):
        value = A[i]
        j = i

        while j > 0 and A[j-1] > value:
            A[j] = A[j-1]
            j -= 1

        A[j] = value

if __name__ == '__main__':
    A = [3, 8, 5, 4, 1, 9, -2]
    insertionSort(A)
    print(A)
