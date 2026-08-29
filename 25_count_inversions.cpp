#include <iostream>
using namespace std;

int main()
{
    int a[10], n;
    int count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Compare every element with the elements after it
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                count++;
            }
        }
    }

    cout << "Number of inversions = " << count;

    return 0;
}


