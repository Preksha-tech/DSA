#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* prev;
    Node* next;
};

// Insert character at end
void insertEnd(Node*& head, Node*& tail, char x)
{
    Node* newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Check palindrome
bool isPalindrome(Node* head, Node* tail)
{
    while (head != NULL && tail != NULL)
    {
        if (head == tail || head->next == tail ||
            head->prev == tail)
            break;

        if (head->data != tail->data)
            return false;

        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    string str;

    cout << "Enter a word: ";
    cin >> str;

    // Create doubly linked list
    for (int i = 0; i < str.length(); i++)
    {
        insertEnd(head, tail, str[i]);
    }

    // Check palindrome
    if (isPalindrome(head, tail))
    {
        cout << "True: It is a Palindrome." << endl;
    }
    else
    {
        cout << "False: It is not a Palindrome." << endl;
    }

    return 0;
}
