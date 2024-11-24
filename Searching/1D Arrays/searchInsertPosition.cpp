#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem Statement: You are given a sorted array arr of distinct values and a target value x.
 * You need to search for the index of the target value in the array.

 * Example 1:
 * Input Format: arr[] = {1,2,4,7}, x = 6
 * Result: 3
 * Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index, the array will still be sorted. {1,2,4,6,7}.

 * Example 2:
 * Input Format: arr[] = {1,2,4,7}, x = 2
 * Result: 1
 * Explanation: 2 is present in the array and so we will return its index i.e. 1.
 */

// ? Lower Bound function
int searchInsert(vector<int> a, int k)
{
    int left = 0, right = a.size() - 1;
    int ans = a.size();

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int key = 6;

    cout << "Insert Position: " << searchInsert(arr, key) << endl;
}