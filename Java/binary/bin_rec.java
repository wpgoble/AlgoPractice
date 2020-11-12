class Main_recur
{
    public static int binary(int[] A, int left, int right, int x)
    {
        if(left > right)
            return -1;

        int mid = left + (right - left) / 2;

        if(x == A[mid])
            return mid;
        else if(x < A[mid])
            return binary(A, left, mid - 1, x);
        else
            return binary(A, mid + 1, right, x);
    }

    public static void main(String[] args)
    {
        int[] A = {2, 5, 6, 8, 9, 10};
        int key = 5;
        int left = 0;
        int right = A.length - 1;
        int index = binary(A, left, right, key);

        if(index != -1)
            System.out.println("Element found at index " + index);
        else
            System.out.println("Element not found in array");
    }
}
