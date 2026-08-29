#include <iostream>
using namespace std;

int main()
{
    int a[6] = {1, 2, 3, 5, 6, 7};
    int n = 7;
    int sum = 0, total;

    total = n * (n + 1) / 2;

    for(int i = 0; i < n - 1; i++)
    {
        sum = sum + a[i];
    }

    cout << "Missing number = " << total - sum;

    return 0;
}

