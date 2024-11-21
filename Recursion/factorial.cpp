#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
    {
        return n;
    }
    return n * fact(n - 1);
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid Number, N is not Natural Number";
        exit(0);
    }

    cout << "Factorial: " << fact(n);
}