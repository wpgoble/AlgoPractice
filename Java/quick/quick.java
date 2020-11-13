import java.util.Arrays;

class Quick
{
    public static void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int[] arr, int start, int end)
    {
        int pivot = arr[end];
        int pIndex = start;

        for(int i = start; i < end; i++)
        {
            if(arr[i] <= pivot)
            {
                swap(arr, i, pIndex);
                pIndex++;
            }
        }

        swap(arr, end, pIndex);
        return pIndex;
    }

    public static void quicksort(int[] arr, int start, int end)
    {
        if(start >= end)
        {
            return;
        }

        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }

    public static void main(String[] args)
    {
        int[] arr = {9, -3, 5, 2, 6, 8, -6, 1, 3};
        quicksort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }
}
