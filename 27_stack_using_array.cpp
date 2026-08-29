#include <iostream>
using namespace std;
#define SIZE 5

int stack[SIZE];
int top = -1;

// Push operation
void push()
{
    int x;

    if(top == SIZE - 1)
    {
        cout << "Stack is Full\n";
    }
    else
    {
        cout << "Enter element: ";
        cin >> x;

        top++;
        stack[top] = x;

        cout << "Element pushed\n";
    }
}

// Pop operation
void pop()
{
    if(top == -1)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

// Check Empty
void isEmpty()
{
    if(top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Stack is not Empty\n";
}

// Check Full
void isFull()
{
    if(top == SIZE - 1)
        cout << "Stack is Full\n";
    else
        cout << "Stack is not Full\n";
}

// Display stack
void display()
{
    if(top == -1)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << "Stack elements:\n";

        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}

// Peek operation
void peek()
{
    if(top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Top element: " << stack[top] << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                isFull();
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 7);

    return 0;
}


