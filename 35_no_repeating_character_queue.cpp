#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    char str[MAX];
    char q[MAX];

    int front = 0;
    int rear = -1;
    int freq[256] = {0};

    cout << "Enter characters: ";
    cin >> str;

    cout << "First non-repeating characters: ";

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        // Count frequency
        freq[ch]++;

        // Enqueue
        rear++;
        q[rear] = ch;

        // Remove repeating characters
        while (front <= rear && freq[q[front]] > 1)
        {
            front++;
        }

        // Display first non-repeating character
        if (front > rear)
            cout << "-1 ";
        else
            cout << q[front] << " ";
    }

    return 0;
}

