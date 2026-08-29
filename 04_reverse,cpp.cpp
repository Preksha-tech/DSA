#include <iostream>
using namespace std;

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
