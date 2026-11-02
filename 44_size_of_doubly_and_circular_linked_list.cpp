#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

// Insert in Doubly Linked List
void insertDoubly(Node*& head, int x)
{
    Node* newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

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
        newNode->prev = temp;
    }
}

// Insert in Circular Linked List
void insertCircular(Node*& head, int x)
{
    Node* newNode = new Node;
    newNode->data = x;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Find size of Doubly Linked List
int sizeDoubly(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Find size of Circular Linked List
int sizeCircular(Node* head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    Node* temp = head;

    do
    {
        count++;
        temp = temp->next;

    } while (temp != head);

    return count;
}

int main()
{
    Node* dHead = NULL;
    Node* cHead = NULL;

    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "\nEnter values for Doubly Linked List:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertDoubly(dHead, x);
    }

    cout << "\nEnter values for Circular Linked List:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertCircular(cHead, x);
    }

    cout << "\nSize of Doubly Linked List = "
         << sizeDoubly(dHead) << endl;

    cout << "Size of Circular Linked List = "
         << sizeCircular(cHead) << endl;

    return 0;
}
