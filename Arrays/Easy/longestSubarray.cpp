#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 ? Time Complexity: O(N^2)
*/
void longestSubarray(vector<int> &arr, int target)
{
    int n = arr.size();

    int start = 0, end = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];

            if (s == target)
            {
                if (j + 1 - i > len)
                {
                    start = i;
                    end = j;
                    len = end + 1 - start;
                }
            }
        }
    }

    cout << "Brute-force:- Sub Array: ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " With Length: " << len << endl;
}

/*
 ? Time Complexity: O(N*logN)
*/
void longestSubarray1(vector<int> &arr, int target)
{
    map<int, int> preSum;
    int n = arr.size();
    int sum = 0, maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == target)
        {
            maxlen = max(maxlen, i + 1);
        }

        int rem = sum - target;

        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxlen = max(maxlen, len);
        }

        if (preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }
    }
    cout << "Hashing:- Longest Subarray length: " << maxlen << endl;
}

/*
 ? Time Complexity: O(2*N)
 ! Unordered maps can be used to reduce Time Complexity to O(N)
*/
void longestSubarray2(vector<int> &arr, int target)
{
    int n = arr.size();

    int left = 0, right = 0;
    int sum = arr[0];
    int maxlen = 0, start = 0, end = 0;

    while (right < n)
    {
        while (left <= right && sum > target)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == target)
        {
            if (maxlen < right - left + 1)
            {
                maxlen = right - left + 1;
                start = left, end = right;
            }
        }

        right++;
        if (right < n)
            sum += arr[right];
    }
    cout << "Two Pointer:- Sub Array: ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " With Length: " << maxlen << endl;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9, -1, 1, -1, 1};
    int k = 10;

    longestSubarray(arr, k);
    longestSubarray1(arr, k);
    longestSubarray2(arr, k);
}