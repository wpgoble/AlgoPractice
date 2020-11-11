// linked list node
class Node
{
    int data;
    Node next;

    Node(int data, Node next)
    {
        this.data = data;
        this.next = next;
    }
}

class Main
{
    // Function to detect cyxle in a linked list 
    // using Floyd's Cycle Detection Algorithm
    public static boolean detectCycle(Node head)
    {
        Node slow = head;
        Node fast = head;

        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                return true;
        }
        return false;
    }

    public static void floyd(int[] arr, int size)
    {
        int slow = arr[0];
        int fast = arr[0];
        int ptr1 = arr[0];
        int ptr2 = arr[0];

        while(true)
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
        System.out.println("Repeat value: " + ptr1);
    }

    public static void main(String[] args)
    {
        int[] keys = { 1, 2, 3, 4, 5};
        int[] arr = {3, 1, 3, 4, 2};
        Node head = null;
        for(int i = keys.length-1; i >= 0; i--)
        {
           head = new Node(keys[i], head);
        }

        head.next.next.next.next.next = head.next.next;
        
        if(detectCycle(head))
            System.out.println("Cycle Found");
        else
            System.out.println("No Cycle Found");

        floyd(arr, 5);
    }
}
