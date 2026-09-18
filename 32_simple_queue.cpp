#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
bool isEmpty()
{
    return (front == -1 || front > rear);
}

// Check if queue is full
bool isFull()
{
    return (rear == MAX - 1);
}

// Insert element into queue
void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }
}

// Delete element from queue
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << queue[front] << " deleted from queue." << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// Display front element
void peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Front element is: " << queue[front] << endl;
    }
}

// Display all elements
void display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Queue elements are: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isEmpty())
                    cout << "Queue is Empty." << endl;
                else
                    cout << "Queue is not Empty." << endl;
                break;

            case 4:
                if (isFull())
                    cout << "Queue is Full." << endl;
                else
                    cout << "Queue is not Full." << endl;
                break;

            case 5:
                peek();
                break;

            case 6:
                display();
                break;

            case 7:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
