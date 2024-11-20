#include <iostream>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(min(N1, N2))
*/
int findGcd(int a, int b)
{
    int gcd = 1;
    int minNum = min(a, b);
    for (int i = 1; i < minNum; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            gcd = i;
        }
    }
    return gcd;
}

/*
Time Complexity: O(min(N1, N2))
Same as Brute-Force, but practically has less number of iterations on average
*/
int findGcd1(int a, int b)
{
    int minNum = min(a, b);
    for (int i = minNum; i > 0; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            return i;
        }
    }
}

/*
Time Complexity: O(log(min(a, b)))
*/
int findGcd2(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    return (a == 0) ? b : a;
}

int main()
{
    int n1, n2;
    cout << "Enter N1 and N2: ";
    cin >> n1 >> n2;

    int gcd = findGcd(n1, n2);
    cout << "GCD:(Brute-force): " << gcd << endl;
    gcd = findGcd1(n1, n2);
    cout << "GCD:(Better): " << gcd << endl;
    gcd = findGcd2(n1, n2);
    cout << "GCD:(Optimal): " << gcd << endl;
}