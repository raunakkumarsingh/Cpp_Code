/*ALGORITHM:-
1.  Reset the slowPointer to point to the head of the linked list and keep the fastPointer at the intersected position.
2.  Move both the fastPointer and slowPointer pointers by one node.
3.  The point at which they will intersect is the starting of the cycle.*/
#include <iostream>
#include <unordered_set>
using namespace std;

// A Linked List Node
struct Node
{
    int data;
    Node* next;
};

// Helper function to create a new node with the given data and
// pushes it onto the list's front
void push(Node*& headRef, int data)
{
    // create a new linked list node from the heap
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

// Function to detect a cycle in a linked list using
// Floyd’s cycle detection algorithm
bool detectCycle(Node* head)
{
    // take two pointers – `slow` and `fast`
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        // move slow by one pointer
        slow = slow->next;

        // move fast by two pointers
        fast = fast->next->next;

        // if they meet any node, the linked list contains a cycle
        if (slow == fast) {
            return true;
        }
    }

    // we reach here if the slow and fast pointer does not meet
    return false;
}

int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }

    // insert cycle
    head->next->next->next->next->next = head->next->next;

    if (detectCycle(head)) {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }

    return 0;
}
