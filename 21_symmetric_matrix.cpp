#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n*(n+1)/2];

    cout << "Enter lower triangular elements: ";

    for(int i = 0; i < n*(n+1)/2; i++)
        cin >> a[i];

    cout << "Symmetric Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cout << a[i*(i+1)/2 + j] << " ";
            else
                cout << a[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }

    return 0;
}

