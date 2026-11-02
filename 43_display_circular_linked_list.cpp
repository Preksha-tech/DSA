#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert node at end
void insertEnd(int x)
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

// Display circular linked list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!";
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    // Print head value again
    cout << head->data << endl;
}

int main()
{
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    cout << "Circular Linked List: ";
    display();

    return 0;
}
