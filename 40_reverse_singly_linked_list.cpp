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

// Reverse linked list
void reverseList(Node*& head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;

        current->next = prev;

        prev = current;
        current = nextNode;
    }

    head = prev;
}

// Display linked list
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

    cout << "Original List: ";
    display(head);

    reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
