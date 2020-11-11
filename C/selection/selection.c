#include <stdio.h>

void swap(int arr[], int i, int j);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {3, 5, 8, 4, 1, 9, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        int min = i;
        int j;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr, min, i);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
