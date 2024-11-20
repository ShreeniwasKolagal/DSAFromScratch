#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Time Complexity: O(log10N + 1) where N is the input number.
The time complexity is determined by the number of digits in the input integer N.
In the worst case when N is a multiple of 10 the number of digits in N is log10N + 1.
Space Complexity : O(1) as only a constant amount of additional memory for the counter regardless of size of the input number.
*/
void countDigits(int n)
{
    // Variable to Store Number of Digits
    int c = 0;

    while (n)
    {
        // Increment Count
        c++;

        // Decrease number of digit by removing last digit
        n /= 10;
    }

    cout << "No. of digits(brute-force): " << c << endl;
}

/*
Time Complexity: O(1)as simple arithmetic operations in constant time are computed on integers.
Space Complexity : O(1)
*/
void countDigits2(int n)
{
    // Variable to Store Number of Digits
    int c;

    c = (int)log10(n) + 1;

    cout << "No. of digits(optimal): " << c << endl;
}

int main()
{
    int n;
    cout << "Enter Integer N: ";
    cin >> n;

    countDigits(n);
    countDigits2(n);
}