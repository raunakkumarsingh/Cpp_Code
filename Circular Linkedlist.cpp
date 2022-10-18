#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printlist(Node *head) //this is used to print all the elem in a clili
{
    if (head == NULL)
        return;
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}
Node *insertBegin(Node *head, int data) //this is in O(n)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        Node *curr = head;
        while (curr != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}
Node *smartInsert(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
} // this is smart insert here instead of finding the
//last node aka tail we ccan just add a node at 2nd place and exachange value
//with the head so the node will remain same ie the last node will still point to the
//head node , but the value will be exached with 2nd node. heence we can insert in
// contant time. GGWP
Node *insertEnd(Node *head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        return temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        curr->next = temp;
        temp->next = head;
        return head;
    }
}
Node *smartEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        temp->data = t;
        head->data = data;
    }
    return temp;
}
//similar to the smart insert , this one inserts in constant time in the end
//of the circularlili (same concept)
Node *delHead(Node *head) //O(n)time
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return (curr->next);
}
Node *smartDel(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head->next;
    head->data = head->next->data;
    head->next = head->next->next;
    delete curr;
    return head;
}
Node *delKth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
        return smartDel(head);
    Node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10); //this is a better way to makeing a lili
    head->next = new Node(20); //without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    head = smartInsert(head, 5);
    // Node *head = NULL;
    head = smartEnd(head, 60);
    head = smartDel(head);

    printlist(head);
}