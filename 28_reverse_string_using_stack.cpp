#include <iostream>
#include <string>
using namespace std;

#define SIZE 50

char stack[SIZE];
int top = -1;

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Push characters into stack
    for(int i = 0; i < str.length(); i++)
    {
        top++;
        stack[top] = str[i];
    }

    cout << "Reversed string: ";

    // Pop characters from stack
    while(top >= 0)
    {
        cout << stack[top];
        top--;
    }

    return 0;
}


