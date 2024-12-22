#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
 * A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas.
 * An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
 * Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas.
 * If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
 * Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
 */

int calculateTotalHours(vector<int> &arr, int hourly)
{
    int n = arr.size(), totalH = 0;

    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)arr[i] / (double)hourly);
    }
    return totalH;
}

/*
 ? Time Complexity: O(max(a[]) * N)
*/
int minimumRateToEatBananas(vector<int> arr, int h)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = 1; i <= maxi; i++)
    {
        int req = calculateTotalHours(arr, i);
        if (req <= h)
            return i;
    }
}

/*
 ? Time Complexity: O(N * log(max(a[])))
*/
int minimumRateToEatBananas1(vector<int> arr, int h)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    int left = 1, right = maxi, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        int totalH = calculateTotalHours(arr, mid);

        if (totalH <= h)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    cout << "Koko should eat atleast " << minimumRateToEatBananas(v, h) << " bananas/hr.\n";
    cout << "Koko should eat atleast " << minimumRateToEatBananas1(v, h) << " bananas/hr.\n";
    return 0;
}