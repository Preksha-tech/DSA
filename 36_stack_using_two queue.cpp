#include <iostream>
using namespace std;

#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

// Push operation
void push(int x)
{
    q2[++r2] = x;

    while (f1 <= r1)
    {
        q2[++r2] = q1[f1++];
    }

    // Copy q2 back to q1
    f1 = 0;
    r1 = -1;

    while (f2 <= r2)
    {
        q1[++r1] = q2[f2++];
    }

    f2 = 0;
    r2 = -1;

    cout << x << " pushed into stack." << endl;
}

// Pop operation
void pop()
{
    if (r1 == -1)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << q1[f1] << " popped from stack." << endl;
        f1++;

        if (f1 > r1)
        {
            f1 = 0;
            r1 = -1;
        }
    }
}

// Display stack
void display()
{
    if (r1 == -1)
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Stack elements: ";

        for (int i = f1; i <= r1; i++)
            cout << q1[i] << " ";

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

