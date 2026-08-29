#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "String without vowels: ";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' &&
           s[i] != 'o' && s[i] != 'u' &&
           s[i] != 'A' && s[i] != 'E' && s[i] != 'I' &&
           s[i] != 'O' && s[i] != 'U')
        {
            cout << s[i];
        }
    }

    return 0;
}


