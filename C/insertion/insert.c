#include <stdio.h>

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(void)
{
    int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

void insertionSort(int arr[], int n)
{
    int i = 0;
    for(i = 1; i < n; i++)
    {
        int val = arr[i];
        int j = i;

        while(j > 0 && arr[j - 1] > val)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = val;
    }
}

void printArray(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
