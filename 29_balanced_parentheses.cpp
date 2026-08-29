#include <iostream>
using namespace std;

#define SIZE 50

char stack[SIZE];
int top = -1;

int main()
{
    char exp[SIZE];

    cout << "Enter parentheses: ";
    cin >> exp;

    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            top++;
            stack[top] = '(';
        }
        else if(exp[i] == ')')
        {
            if(top == -1)
            {
                cout << "Not Balanced";
                return 0;
            }

            top--;
        }
    }

    if(top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}


