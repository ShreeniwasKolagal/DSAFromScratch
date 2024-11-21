#include <iostream>
using namespace std;

int fib(int n)
{

    // Base Condition.
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 4;
    cout << fib(n) << endl;
    return 0;
}