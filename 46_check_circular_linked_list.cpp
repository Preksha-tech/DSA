#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
void insertEnd(Node*& head, int x)
{
    Node* newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Check whether linked list is circular
bool isCircular(Node* head)
{
    if (head == NULL)
        return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
        return true;
    else
        return false;
}

int main()
{
    Node* head = NULL;

    int n, x, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;

        insertEnd(head, x);
    }

    cout << "\n1. Make Circular Linked List";
    cout << "\n2. Keep Normal Linked List";
    cout << "\nEnter choice: ";
    cin >> choice;

    // Connect last node to first node
    if (choice == 1 && head != NULL)
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = head;
    }

    // Check result
    if (isCircular(head))
    {
        cout << "\nTrue: It is a Circular Linked List.";
    }
    else
    {
        cout << "\nFalse: It is not a Circular Linked List.";
    }

    return 0;
}
