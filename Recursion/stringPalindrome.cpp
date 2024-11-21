#include <iostream>
#include <algorithm>
using namespace std;

bool palindrome(int i, string s)
{
    // if i exceeds half length, we have checked all index and it is palindrome
    if (i >= s.length() / 2)
        return true;

    // Check the index for palindrome
    if (s[i] != s[s.length() - i - 1])
        return false;

    return palindrome(i + 1, s);
}

int main()
{
    string s = "madam";
    cout << (palindrome(0, s) == 1 ? "String is Palindrome" : "String is NOT Palindrome");
    cout << endl;
    return 0;
}