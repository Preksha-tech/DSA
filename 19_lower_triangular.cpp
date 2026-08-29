#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n*(n+1)/2];

    cout << "Enter elements: ";
    for(int i = 0; i < n*(n+1)/2; i++)
        cin >> a[i];

    int k = 0;

    cout << "Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}

