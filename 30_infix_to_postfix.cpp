#include <iostream>
using namespace std;

char stack[50];
int top = -1;

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/')
        return 2;

    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i = 0, k = 0;
    char ch;

    cout << "Enter infix expression: ";
    cin >> infix;

    while(infix[i] != '\0')
    {
        ch = infix[i];

        // Operand
        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z'))
        {
            postfix[k] = ch;
            k++;
        }
        // Opening bracket
        else if(ch == '(')
        {
            top++;
            stack[top] = ch;
        }
        // Closing bracket
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[k] = stack[top];
                k++;
                top--;
            }

            top--;   // Remove '('
        }
        // Operator
        else
        {
            while(top != -1 &&
                  priority(stack[top]) >= priority(ch))
            {
                postfix[k] = stack[top];
                k++;
                top--;
            }

            top++;
            stack[top] = ch;
        }

        i++;
    }
    // Remove remaining operators
    while(top != -1)
    {
        postfix[k] = stack[top];
        k++;
        top--;
    }

    postfix[k] = '\0';

    cout << "Postfix expression: " << postfix;

    return 0;
}


