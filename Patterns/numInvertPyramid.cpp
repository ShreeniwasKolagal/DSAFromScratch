#include <iostream>
using namespace std;

/*
1      1
12    21
123  321
12344321
*/

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        for (int j = 0; j < (n - i) * 2; j++)
        {
            cout << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}