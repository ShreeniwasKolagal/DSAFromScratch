#include <iostream>
using namespace std;

int checkPalindrome(int n)
{
    // If a number is palindrome, the reversed number should be same as original number

    int temp = n; // Copy of Original Number
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

    // Returns 1 if Palindrome else 0
    return temp == rev;
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    n = checkPalindrome(n);

    cout << ((n == 1) ? "Number is Palindrome" : "Number is NOT Palindrome");
}