#include <iostream>
#include <vector>
using namespace std;

// Function to generate factorial
int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

/*
 ? If in question row and col is given and told to get the number. Use this function to get that specific element
*/
int ncr(int r, int c)
{
    return fact(r) / (fact(c) * fact(r - c));
}

/*
 ? Function to generate a specific row of pascal triangle. Use this if problem requires specific row
*/
vector<int> generateRow(int n)
{
    vector<int> ansRow;

    for (int i = 0; i < n; i++)
    {
        ansRow.push_back(ncr(n - 1, i));
    }
    return ansRow;
}

/*
 ? Uses all other functions to generate a fully complete pascal's triangle
*/
vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}