#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x)
{
    Node* n = new Node;
    n->data = x;

    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }
}

// Insert at end
void insertEnd(int x)
{
    Node* n = new Node;
    n->data = x;

    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }
}

// Insert after a node
void insertAfter(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
        {
            Node* n = new Node;
            n->data = x;
            n->next = temp->next;
            temp->next = n;

            cout << "Inserted!" << endl;
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Node not found!" << endl;
}

// Insert before a node
void insertBefore(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == key)
    {
        insertBegin(x);
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != key)
        temp = temp->next;

    if (temp->next == head)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* n = new Node;
    n->data = x;
    n->next = temp->next;
    temp->next = n;

    cout << "Inserted!" << endl;
}

// Delete a specific node
void deleteNode(int key)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    do
    {
        if (temp->data == key)
        {
            if (temp->next == head)
            {
                if (temp == head)
                {
                    delete temp;
                    head = NULL;
                }
                else
                {
                    prev->next = head;
                    delete temp;
                }
            }
            else
            {
                if (temp == head)
                {
                    Node* last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                    delete temp;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
            }

            cout << "Node deleted!" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    cout << "Node not found!" << endl;
}

// Search a node
void searchNode(int key)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    int pos = 1;

    do
    {
        if (temp->data == key)
        {
            cout << "Node found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

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

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;

    } while (temp != head);

    cout << "HEAD" << endl;
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
