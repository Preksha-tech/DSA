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

// Count and delete all occurrences
int countDelete(Node*& head, int key)
{
    int count = 0;

    while (head != NULL && head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        }
        else
        {
            temp = temp->next;
        }
    }

    return count;
}

// Display list
void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original List: ";
    display(head);

    int count = countDelete(head, key);

    cout << "Count: " << count << endl;

    cout << "Updated List: ";
    display(head);

    return 0;
}
