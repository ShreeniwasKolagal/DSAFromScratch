#include <iostream>
#include <vector>
using namespace std;

/*
 * You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
 * You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
 * Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
 */

bool possible(vector<int> arr, int day, int k, int m)
{
    int n = arr.size();

    int cnt = 0, nBouq = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            cnt++;
        else
        {
            nBouq += (cnt / k);
            cnt = 0;
        }
    }

    // In case loop ends before adding last case.
    nBouq += (cnt / k);
    return (nBouq >= m);
}

/*
 ? Time Complexity: O(N * (max(arr[])-min(arr[])+1))
*/
int roseGarden(vector<int> arr, int k, int m)
{
    int n = arr.size();
    if (k * m > n)
        return -1;

    int mini = INT16_MAX, maxi = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, i, k, m))
            return i;
    }
    return -1;
}

/*
 ? Time Complexity: O(N * log(max(arr[])-min(arr[])+1))
*/
int roseGarden1(vector<int> arr, int k, int m)
{
    int n = arr.size();
    if (k * m > n)
        return -1;

    int mini = INT16_MAX, maxi = INT16_MIN;

    for (auto i : arr)
    {
        mini = min(mini, i);
        maxi = max(maxi, i);
    }

    int low = mini, high = maxi, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (possible(arr, mid, k, m))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;

    cout << "Bouquets can be made on day " << roseGarden(arr, k, m) << endl;
    cout << "Bouquets can be made on day " << roseGarden1(arr, k, m) << endl;
}