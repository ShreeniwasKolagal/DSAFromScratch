#include <iostream>
using namespace std;

void printRange(int n, int i = 1)
{
    cout << i << " ";
    if (i < n)
    {
        printRange(n, i + 1);
    }
}
void printRevRange(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        printRevRange(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << "Range: ";
    printRange(n);
    cout << endl
         << "Range in Reverse: ";
    printRevRange(n);
}