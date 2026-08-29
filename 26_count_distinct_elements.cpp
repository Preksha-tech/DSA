#include <iostream>
using namespace std;

int main()
{
    int a[20], n;
    int count = 0;
    bool found;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        found = false;

        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                found = true;
                break;
            }
        }

        if(found == false)
        {
            count++;
        }
    }

    cout << "Total distinct elements = " << count;

    return 0;
}


