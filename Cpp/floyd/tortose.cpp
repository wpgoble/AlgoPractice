#include <iostream>

using namespace std;

void findDuplicate(int arr[], int size);

int main()
{
    int arr[5] = {3, 1, 3, 4, 2};
    findDuplicate(arr, 5);
    return 0;
}

void findDuplicate(int arr[], int size)
{ 
    int slow = arr[0];
    int fast = arr[0];

    while(1)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if(slow == fast)
            break;
    }

    int ptr1 = arr[0];
    int ptr2 = slow;

    while(ptr1 != ptr2)
    {
        ptr1 = arr[ptr1];
        ptr2 = arr[ptr2];
    }

    printf("repeat value: %d\n", ptr1);
}
