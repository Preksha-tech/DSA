#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[5] = {"Mango", "Apple", "Banana", "Orange", "Grapes"};
    string temp;

    for(int i = 0; i < 5 - 1; i++)
    {
        for(int j = 0; j < 5 - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";

    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}


