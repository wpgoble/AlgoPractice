#include <stdio.h>

void floyd(int arr[], int size);

int main()
{
    int arr[5] = {3, 1, 3, 4, 2};
    floyd(arr, 5);

    return 0;
}

void floyd(int arr[], int size)
{
    int i = 0;
    int slow = arr[0];
    int fast = arr[0];
    int ptr1 = arr[0];
    int ptr2 = arr[0];

    printf("Original Array: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    while(1)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if(slow == fast)
            break;
    }

    ptr2 = slow;
    
    while(ptr1 != ptr2)
    {
        ptr1 = arr[ptr1];
        ptr2 = arr[ptr2];
    }
    printf("repeat value: %d\n", ptr1);
}
