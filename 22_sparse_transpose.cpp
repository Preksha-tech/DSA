#include <iostream>
using namespace std;

int main()
{
    int a[10][3], t[10][3];
    int n;

    cout << "Enter rows, columns and non-zero elements: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    n = a[0][2];

    cout << "Enter triplet elements:\n";
    for(int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    // Interchange row and column
    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    for(int i = 1; i <= n; i++)
    {
        t[i][0] = a[i][1];
        t[i][1] = a[i][0];
        t[i][2] = a[i][2];
    }

    cout << "\nTranspose:\n";

    for(int i = 0; i <= n; i++)
        cout << t[i][0] << " "
             << t[i][1] << " "
             << t[i][2] << endl;

    return 0;
}

