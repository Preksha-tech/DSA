#include <iostream>
using namespace std;

int main()
{
    int a[7] = {64, 34, 25, 12, 22, 11, 90};
    int temp;

    cout << "Original array: ";
    for(int i = 0; i < 7; i++)
        cout << a[i] << " ";

    cout << "\n\nSorting steps:\n";

    for(int i = 0; i < 7 - 1; i++)
    {
        cout << "\nPass " << i + 1 << ":\n";

        for(int j = 0; j < 7 - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                // Swapping
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                // Display array after each swap
                for(int k = 0; k < 7; k++)
                    cout << a[k] << " ";

                cout << endl;
            }
        }
    }

    cout << "\nFinal sorted array: ";
    for(int i = 0; i < 7; i++)
        cout << a[i] << " ";

    return 0;
}


