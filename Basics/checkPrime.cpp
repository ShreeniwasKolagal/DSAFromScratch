#include <iostream>
#include <cmath>
using namespace std;

int checkPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int checkPrime1(int n)
{
    if (n <= 1)
        return 0;

    int sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << ((checkPrime(n) == 1) ? "Number is Prime" : "Number is NOT Prime") << endl;
    cout << ((checkPrime1(n) == 1) ? "Number is Prime" : "Number is NOT Prime");

    return 0;
}