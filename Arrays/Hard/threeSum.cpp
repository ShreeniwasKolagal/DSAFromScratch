#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
 ? Time Complexity: O( N^3 * logK ) K = Number of unique triplets
*/
void threeSum(vector<int> arr, int n, int target)
{
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    cout << "Brute-Force:\n";
    for (auto i : s)
    {
        for (auto item : i)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

/*
 ? Time Complexity: O( N^2 * logK ) K = Number of unique triplets
*/
void threeSum1(vector<int> arr, int n, int target)
{
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Find the missing number
            int third = target - (arr[i] + arr[j]);

            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    cout << "Better Approach(Two Loops):\n";
    for (auto i : s)
    {
        for (auto item : i)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

void threeSum2(vector<int> arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < target)
            {
                j++;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++, k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (k > j && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    cout << "Optimal Approach:\n";
    for (auto i : ans)
    {
        for (auto item : i)
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int k = 0;

    threeSum(arr, arr.size(), k);
    threeSum1(arr, arr.size(), k);
    threeSum2(arr, arr.size(), k);
}