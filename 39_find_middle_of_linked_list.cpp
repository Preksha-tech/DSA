#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
void insertEnd(Node*& head, int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find middle element
void findMiddle(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
}

// Display list
void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Linked List: ";
    display(head);

    findMiddle(head);

    return 0;
}
