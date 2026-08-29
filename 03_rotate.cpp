#include <iostream>
using namespace std;

int main()
{
int a[100], n, k, ch;
cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    k = k % n;

    cout << "1. Left  2. Right\n";
    cin >> ch;

    if (ch == 1) {
        for (int r = 0; r < k; r++) {
            int x = a[0];
            for (int i = 0; i < n - 1; i++)
                a[i] = a[i + 1];
            a[n - 1] = x;
        }
    }
    else {
        for (int r = 0; r < k; r++) {
            int x = a[n - 1];
            for (int i = n - 1; i > 0; i--)
                a[i] = a[i - 1];
            a[0] = x;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

return 0;
}
