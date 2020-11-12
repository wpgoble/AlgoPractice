class Main
{
    public static int binary(int[] A, int x)
    {
        int left = 0;
        int right = A.length - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(x == A[mid])
            {
                return mid;
            }
            else if(x < A[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        int[] A = { 2, 5, 6, 8, 9, 10};
        int key = 5;
        int index = binary(A, key);
        
        if(index != -1)
        {
            System.out.println("Element found at index " + index);
        }
        else
        {
            System.out.println("Element not found in the array");
        }
    }
}

