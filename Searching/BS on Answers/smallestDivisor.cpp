#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
 ? Time Complexity: O(max(arr[]) * N)
*/
int smallestDivisor(vector<int> arr, int limit)
{
    int n = arr.size();
    int maxx = *max_element(arr.begin(), arr.end());

    for (int i = 1; i < maxx; i++)
    {
        int sum = 0;

        for (auto ele : arr)
            sum += ceil((double)ele / (double)i);

        if (sum <= limit)
            return i;
    }
    return -1;
}

/*
 ? Time Complexity: O(log(max(arr[])) * N)
*/
int smallestDivisor1(vector<int> arr, int limit)
{
    int n = arr.size();
    int maxx = *max_element(arr.begin(), arr.end());

    int left = 1, right = maxx;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;

        for (auto ele : arr)
            sum += ceil((double)ele / (double)mid);

        if (sum <= limit)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    cout << "Smallest Divisor: " << smallestDivisor(arr, limit) << endl;
    cout << "Smallest Divisor: " << smallestDivisor1(arr, limit) << endl;
}