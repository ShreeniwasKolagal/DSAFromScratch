#include <bits/stdc++.h>
using namespace std;

void rightAngledTriangle(int n)
{
    /*
     *
     * *
     * * *
     */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        1
        1 2
        1 2 3
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    /*
        3
        3 2
        3 2 1
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << n - j << " ";
        }
        cout << endl;
    }

    /*
        1
        2 2
        3 3 3
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N:";
    cin >> n;

    rightAngledTriangle(n);
    return 0;
}