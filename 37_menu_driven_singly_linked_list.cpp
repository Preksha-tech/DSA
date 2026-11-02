#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int x)
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

// Insert before a specific node
void insertBefore(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == key)
    {
        insertBeginning(x);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert after a specific node
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

    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Node deleted!" << endl;
}

// Delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Node deleted!" << endl;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    cout << "Node deleted!" << endl;
}

// Delete specific node
void deleteSpecific(int key)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == key)
    {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted!" << endl;
}

// Search node
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

// Display linked list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int choice, x, key;

    do
    {
        cout << "\n----- SINGLY LINKED LIST -----" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before Node" << endl;
        cout << "4. Insert After Node" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete Specific Node" << endl;
        cout << "8. Search Node" << endl;
        cout << "9. Display List" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBeginning(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> x;
                cout << "Insert before which node? ";
                cin >> key;
                insertBefore(key, x);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> x;
                cout << "Insert after which node? ";
                cin >> key;
                insertAfter(key, x);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter node to delete: ";
                cin >> key;
                deleteSpecific(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                display();
                break;

            case 0:
                cout << "Program ended!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
