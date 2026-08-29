#include <iostream>
using namespace std;

int main()
{
    int a[20][3], b[20][3], c[40][3];
    int i = 1, j = 1, k = 1;

    cout << "Enter rows, columns and non-zero elements of A: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    cout << "Enter elements of A:\n";
    for(int x = 1; x <= a[0][2]; x++)
        cin >> a[x][0] >> a[x][1] >> a[x][2];

    cout << "Enter rows, columns and non-zero elements of B: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];

    cout << "Enter elements of B:\n";
    for(int x = 1; x <= b[0][2]; x++)
        cin >> b[x][0] >> b[x][1] >> b[x][2];

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while(i <= a[0][2] && j <= b[0][2])
    {
        if(a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];

            i++;
            j++;
            k++;
        }
        else if(a[i][0] < b[j][0])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];

            i++;
            k++;
        }
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];

            j++;
            k++;
        }
    }

    while(i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];

        i++;
        k++;
    }

    while(j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];

        j++;
        k++;
    }

    c[0][2] = k - 1;

    cout << "\nAddition:\n";

    for(int x = 0; x <= c[0][2]; x++)
        cout << c[x][0] << " "
             << c[x][1] << " "
             << c[x][2] << endl;

    return 0;
}

