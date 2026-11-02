#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x)
{
    Node* n = new Node;
    n->data = x;
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Insert at end
void insertEnd(int x)
{
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL)
    {
        n->prev = NULL;
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Insert after a node
void insertAfter(int key, int x)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* n = new Node;
    n->data = x;

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;

    cout << "Inserted!" << endl;
}

// Insert before a node
void insertBefore(int key, int x)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* n = new Node;
    n->data = x;

    n->prev = temp->prev;
    n->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = n;
    else
        head = n;

    temp->prev = n;

    cout << "Inserted!" << endl;
}

// Delete a specific node
void deleteNode(int key)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Node deleted!" << endl;
}

// Search a node
void searchNode(int key)
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Node found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Node not found!" << endl;
}

// Display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "NULL <-> ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int ch, x, key;

    do
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After";
        cout << "\n4. Insert Before";
        cout << "\n5. Delete Node";
        cout << "\n6. Search Node";
        cout << "\n7. Display";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBegin(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter new value: ";
                cin >> x;
                cout << "Insert after which node? ";
                cin >> key;
                insertAfter(key, x);
                break;

            case 4:
                cout << "Enter new value: ";
                cin >> x;
                cout << "Insert before which node? ";
                cin >> key;
                insertBefore(key, x);
                break;

            case 5:
                cout << "Enter node to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 6:
                cout << "Enter node to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 7:
                display();
                break;

            case 0:
                cout << "Exit!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (ch != 0);

    return 0;
}
