#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 ? Time Complexity: O(N^2)
 ? Space Complexity: O(N^2)
*/
void rotate(vector<vector<int>> mat)
{
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotated[j][(n - 1) - i] = mat[i][j];

    cout << "Rotated:\n";
    for (auto i : rotated)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

/*
 ? Time Complexity: O(N^2)+O(N^2)
*/
void rotate1(vector<vector<int>> mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);

    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    cout << "Rotated:\n";
    for (auto i : mat)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(arr);
    rotate1(arr);
}