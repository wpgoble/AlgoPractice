import java.util.Arrays;

class Main
{
    public static void insertionSort(int[] arr)
    {
        for(int i = 1; i < arr.length; i++)
        {
            int val = arr[i];
            int j = i;

            while(j > 0 && arr[j-1] > val)
            {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = val;
        }
    }

    public static void main(String[] args)
    {
        int[] arr = { 3, 8, 5, 4, 1, 9, -2 };
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
