#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    int queue[MAX];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> queue[i];
    }

    int half = n / 2;

    cout << "Interleaved queue: ";

    for (int i = 0; i < half; i++)
    {
        cout << queue[i] << " ";
        cout << queue[i + half] << " ";
    }

    return 0;
}

