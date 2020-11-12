#include <stdio.h>

int binarySearch(int[], int, int);

int main(void)
{
    int A[] = {2, 5, 6, 8, 9, 10};
    int target = 5;
    int n = sizeof(A) / sizeof(A[0]);
    int index = binarySearch(A, n, target);

    if(index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found in the array\n");

    return 0;
}

int binarySearch(int A[], int N, int target)
{
    int low = 0;
    int high = N - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(target == A[mid])
            return mid;
        else if(target < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
