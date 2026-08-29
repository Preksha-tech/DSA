#include <iostream>
using namespace std;

int main()
{
    int a[10][3], b[10][3];
    int A[10][10] = {0};
    int B[10][10] = {0};
    int C[10][10] = {0};

    int r1, c1, r2, c2;

    cout << "Enter rows, columns and non-zero elements of A: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];

    for(int i = 1; i <= a[0][2]; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cout << "Enter rows, columns and non-zero elements of B: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];

    for(int i = 1; i <= b[0][2]; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    r1 = a[0][0];
    c1 = a[0][1];
    r2 = b[0][0];
    c2 = b[0][1];

    if(c1 != r2)
    {
        cout << "Multiplication not possible";
        return 0;
    }

    // Convert triplet to normal matrix
    for(int i = 1; i <= a[0][2]; i++)
        A[a[i][0]][a[i][1]] = a[i][2];

    for(int i = 1; i <= b[0][2]; i++)
        B[b[i][0]][b[i][1]] = b[i][2];

    // Multiplication
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            for(int k = 0; k < c1; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult in Triplet Form:\n";

    int count = 0;

    // Count non-zero elements
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            if(C[i][j] != 0)
                count++;
        }
    }

    cout << r1 << " " << c2 << " " << count << endl;

    // Print triplet
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            if(C[i][j] != 0)
                cout << i << " " << j << " " << C[i][j] << endl;
        }
    }

    return 0;
}


