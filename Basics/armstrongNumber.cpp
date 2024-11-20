#include <iostream>
#include <cmath>
using namespace std;

void checkArmstrong(int n)
{
    // Store the number of digits
    int digits = (int)log10(n) + 1;
    int temp = n, digit = 0;
    int sum = 0;

    while (temp)
    {
        digit = temp % 10; // Extract the last digit
        int power = 1;     // Compute digit^digits using integer arithmetic
        for (int i = 0; i < digits; i++)
        {
            power *= digit;
        }
        sum += power; // Add the result to the sum
        temp /= 10;   // Remove the last digit
    }

    // Compare and print the result
    cout << ((sum == n) ? "Number is an Armstrong Number" : "Number is NOT an Armstrong Number") << endl;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    checkArmstrong(n);
}