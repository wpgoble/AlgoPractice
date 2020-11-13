#include <iostream>
#include <algorithm>

using namespace std;

int Partition(int[], int, int);
void quicksort(int[], int, int);

int main()
{
    int arr[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

int Partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quicksort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int pivot = Partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}
