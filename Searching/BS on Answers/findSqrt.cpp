#include <iostream>
#include <cmath>
using namespace std;

/*
 * The problem statement is to find Square Root of a Number.
 * If N is not perfect number, we return the largest number with square smaller than N
 */

int findSqrt(int n)
{
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
    }
    return ans;
}

int findSqrt1(int n)
{
    return (int)sqrt(n);
}

/*
 ? Time Complexity: O(logN)
*/
int findSqrt2(int n)
{
    int low = 1, high = n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if (val <= (long long)(n))
        {
            // Eliminate left half
            low = mid + 1;
        }
        else
        {
            // Eliminate right half
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int N = 5;

    cout << "Sqrt of N(Linear-search): " << findSqrt(N) << endl;
    cout << "Sqrt of N(Built-in): " << findSqrt1(N) << endl;
    cout << "Sqrt of N(Binary-search): " << findSqrt2(N) << endl;
}