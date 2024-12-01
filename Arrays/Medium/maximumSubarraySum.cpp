#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 ? Time Complexity: O(N^3)
*/
void maximumSum(vector<int> arr, int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                // Find sum of arr[i ... j]
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    cout << "Maximum Sum(Brute-force): " << maxi << endl;
}

/*
 ? Time Complexity: O(N^2)
*/
void maximumSum1(vector<int> arr, int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }

    cout << "Maximum Sum(Better-approach): " << maxi << endl;
}
void maximumSum2(vector<int> arr, int n)
{
    int maxi = 0, start = 0, ansstart = 0, ansend = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansstart = start;
            ansend = i;
        }

        if (sum < 0)
            sum = 0;
    }

    cout << "Maximum Sum(Kadane's Algorithm): " << maxi << "\nSubarray: [ ";
    for (int i = ansstart; i < ansend + 1; i++)
        cout << arr[i] << " ";
    cout << "]\n";
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    maximumSum(arr, n);
    maximumSum1(arr, n);
    maximumSum2(arr, n);
}