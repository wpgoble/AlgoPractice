#include <stdio.h>

int binary(int[], int, int, int);

int main(void)
{
    int A[] = {2, 5, 6, 8, 9, 10};
    int target = 5;
    int n = sizeof(A) / sizeof(A[0]);
    int low = 0;
    int high = n - 1;
    int index = binary(A, low, high, target);

    if(index != -1)
        printf("Element is found at index %d\n", index);
    else
        printf("Element is not found in the array\n");

    return 0;
}

int binary(int A[], int low, int high, int tar)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(tar == A[mid])
        return mid;
    else if(tar < A[mid])
        return binary(A, low, mid - 1, tar);
    else
        return binary(A, mid+1, high, tar);
}
