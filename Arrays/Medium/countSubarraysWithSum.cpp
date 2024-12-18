#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N^3)
*/
void countSubarray(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            // Calculate sum of subarray a[i...j]
            for (int k = i; k <= j; k++)
                sum += arr[k];

            if (sum == k)
                cnt++;
        }
    }

    cout << "Count: " << cnt << endl;
}

/*
 ? Time Complexity: O(N^2)
*/
void countSubarray1(vector<int> arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            //  Calculate sum of subarray a[i...j]
            sum += arr[j];

            if (sum == k)
                cnt++;
        }
    }
    cout << "Count: " << cnt << endl;
}

void countSubarray2(vector<int> arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    int cnt = 0, presum = 0;

    // Setting up the map
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // Add current element to presum
        presum += arr[i];

        int remove = presum - k;

        // Add number of subarrays to be removed
        cnt += mpp[remove];

        // Add count to prefix sum
        mpp[presum] += 1;
    }
    cout << "Count: " << cnt << endl;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    countSubarray(arr, k);
    countSubarray1(arr, k);
    countSubarray2(arr, k);
}