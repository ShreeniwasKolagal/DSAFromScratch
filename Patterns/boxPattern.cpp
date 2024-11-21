#include <iostream>
using namespace std;

/*

33333
32223
32123
32223
33333

*/

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i, bottom = j, left = (2 * n - 2) - j, right = (2 * n - 2) - i;

            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << endl;
    }
}