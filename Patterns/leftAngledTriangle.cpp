#include <iostream>
using namespace std;

void leftAngledTriangle(int n)
{
    /*
     *****
     ****
     ***
     **
     *
     */

    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
            cout << "*";
        cout << endl;
    }
}

void leftAngledTriangleNumber(int n)
{
    /*
     12345
     1234
     123
     12
     1
     */

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    leftAngledTriangle(n);
    leftAngledTriangleNumber(n);

    return 0;
}