#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return n;
    }
    return n + sum(n - 1);
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

    cout << "Sum till First N Natural Numbers: " << sum(n);
}