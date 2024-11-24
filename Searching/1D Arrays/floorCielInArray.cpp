#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
 * The floor of x is the largest element in the array which is smaller than or equal to x.
 * The ceiling of x is the smallest element in the array greater than or equal to x.
 */

/*
 ? Time Complexity: O(2 * logN)
 ? Reason: We use binary search twice, once for floor and other for ciel
*/
pair<int, int> getFloorCiel(vector<int> a, int k)
{
    int floor = a.front();
    int ciel = a.back();

    int left = 0, right = a.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= k)
        {
            floor = a[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    left = 0, right = a.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= k)
        {
            ciel = a[mid];
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return {floor, ciel};
}

int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;

    pair<int, int> ans = getFloorCiel(arr, x);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
}