#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
Time Complexity: O(N) where N is the input number.
The algorithm iterates through each number from 1 to n once to check if it is a divisor.

Space Complexity : O(N) where N is the input number.
The algorithm iterates through each number from 1 to n once to check if it is a divisor.
*/
vector<int> printDivisors(int n)
{
    vector<int> divisors;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}

/*
Time Complexity: O(sqrt(N)) where N is the input number.
The algorithm iterates through each number from 1 to the square root of N once to check if it is a divisor.

Space Complexity : O(2*sqrt(N))where N is the input number.
This approach allocates memory for an array to hold all the divisors. The size of this array could go to be 2*(sqrt(N)).
*/
vector<int> printDivisors1(int n)
{
    vector<int> divisors;
    int sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);

            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> a = printDivisors(n);
    cout << "Divisors of Number (Brute-force): ";
    for (auto item : a)
    {
        cout << item << " ";
    }
    cout << endl
         << "Divisors of Number (Optimal): ";
    a = printDivisors1(n);
    for (auto item : a)
    {
        cout << item << " ";
    }
    return 0;
}