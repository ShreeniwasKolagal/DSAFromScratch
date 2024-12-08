#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> a)
{
    // Rows
    int n = a.size();
    // Cols
    int m = a[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            cout << a[top][i] << " ";

        top++;

        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";

        right--;

        for (int i = right; i >= left; i--)
            cout << a[bottom][i] << " ";

        bottom--;

        for (int i = bottom; i >= top; i--)
            cout << a[i][left] << " ";

        left++;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    printSpiral(arr);
}