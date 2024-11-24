#include <iostream>
using namespace std;

long long func(int n, int pow)
{
    long long ans = 1;
    while (pow)
    {
        ans = ans * n;
        pow--;
    }
    return ans;
}

int nthRoot(int m, int n)
{
    for (int i = 1; i < m; i++)
    {
        if (func(i, n) == (long long)m)
        {
            return i;
        }
        else if (func(i, n) > m)
        {
            return -1;
        }
    }
}
int nthRoot1(int m, int n)
{
    int left = 1, right = m;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (func(mid, n) == (long long)m)
        {
            return mid;
        }
        else if (func(mid, n) < (long long)m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int m;
    cout << "Enter Number: ";
    cin >> m;
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << "Nth Root(Linear-search): " << nthRoot(m, n) << endl;
    cout << "Nth Root(Binary-search): " << nthRoot1(m, n) << endl;
}