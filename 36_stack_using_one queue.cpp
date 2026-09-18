#include <iostream>
using namespace std;

#define MAX 100

int q[MAX];
int front = 0;
int rear = -1;

// Push operation
void push(int x)
{
    if (rear == MAX - 1)
    {
        cout << "Stack is Full!" << endl;
        return;
    }

    // Insert new element
    rear++;
    q[rear] = x;

    // Move previous elements after new element
    for (int i = rear; i > front; i--)
    {
        q[i] = q[i - 1];
    }

    q[front] = x;

    cout << x << " pushed into stack." << endl;
}

// Pop operation
void pop()
{
    if (rear < front)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << q[front] << " popped from stack." << endl;
        front++;

        if (front > rear)
        {
            front = 0;
            rear = -1;
        }
    }
}

// Display stack
void display()
{
    if (rear < front)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Stack elements: ";

        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";

        cout << endl;
    }
}

int main()
{
    int choice, x;

    do
    {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

