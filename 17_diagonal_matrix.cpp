#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];

    cout << "Enter diagonal elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                cout << a[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}

