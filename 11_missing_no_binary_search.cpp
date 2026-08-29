#include <iostream>
using namespace std;

int main()
{
    int a[6] = {1, 2, 3, 5, 6, 7};
    int n = 7;
    int low = 0, high = n - 2;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Missing number = " << low + 1;

    return 0;
}

