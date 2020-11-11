#include<iostream>
#include<unordered_set>

using namespace std;

// data structure to store a linked list node
struct Node
{
    int data;
    Node* next;
};

// helper function to create a new node with the 
// given data and pushes it onto the front of the 
// list
void push(Node* &headRef, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

// Function to detect cucle in a linked list using 
// Floyd's Cycle detection algorithm
bool detectCycle(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }

    return false;
}

int main()
{
    int keys[] = { 1, 2, 3, 4, 5};
    int n = sizeof(keys) / sizeof(keys[0]);
    Node* head = nullptr;
    for(int i = n - 1; i >= 0; i--)
        push(head, keys[i]);
    head->next->next->next->next->next = head->next->next;
    if(detectCycle(head))
        cout << "Cycle found\n";
    else
        cout << "No cycle found\n";

    return 0;
}
