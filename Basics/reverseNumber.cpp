#include <iostream>
using namespace std;

/*
Time Complexity: O(log10N + 1) where N is the input number.
The time complexity is determined by the number of digits in the input integer N.
In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.

Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.
*/
int reverseNumber(int n)
{
    int temp = n;
    int rev = 0;
    int digit;

    while (n)
    {
        // Get last digit from Number
        digit = n % 10;

        // Add the digit to Reverse Number
        rev = rev * 10 + digit;

        // Get rid of last digit
        n /= 10;
    }

    return rev;
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    n = reverseNumber(n);
    cout << "Reversed Number: " << n;
}