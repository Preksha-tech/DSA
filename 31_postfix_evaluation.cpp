#include <iostream>
using namespace std;

int stack[50];
int top = -1;

int main()
{
    char postfix[50];
    int i = 0;
    int a, b, result;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    while(postfix[i] != '\0')
    {
        // If operand
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            top++;
            stack[top] = postfix[i] - '0';
        }

        // If operator
        else
        {
            b = stack[top];
            top--;

            a = stack[top];
            top--;

            if(postfix[i] == '+')
                result = a + b;

            else if(postfix[i] == '-')
                result = a - b;

            else if(postfix[i] == '*')
                result = a * b;

            else if(postfix[i] == '/')
                result = a / b;

            top++;
            stack[top] = result;
        }

        i++;
    }

    cout << "Result = " << stack[top];

    return 0;
}


