#include <iostream>
#include <vector>
using namespace std;

/*
? Time Complexity: O(N), where N = size of the given array.
? Space Complexity: O(1) as we are using no extra space.
*/
int upperBound(vector<int> a, int x)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return i;
    }
    return n;
}

/*
? Time Complexity: O(logN)
? Space Complexity: O(1)
*/
int upperBound1(vector<int> a, int x)
{
    int left = 0, right = a.size() - 1;
    int ans = a.size();

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] > x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int x = 9;

    int i = upperBound(arr, x);
    if (i == arr.size())
        cout << "No Upper Bound found" << endl;
    else
        cout << "Upper Bound at Index: " << i << endl;

    i = upperBound1(arr, x);
    if (i == arr.size())
        cout << "No Upper Bound found" << endl;
    else
        cout << "Upper Bound at Index: " << i << endl;
}