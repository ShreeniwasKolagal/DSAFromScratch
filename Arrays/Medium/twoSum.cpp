#include <iostream>
#include <map>
using namespace std;

/*
? Time Complexity: O(N^2).

? Space Complexity: O(1) as we are not using any extra space.
*/
pair<pair<int, int>, pair<int, int>> twoSum(int *a, int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) == k)
                return {{a[i], a[j]}, {i, j}};
        }
    }
    return {{-1, -1}, {-1, -1}};
}

/*
? Time Complexity: O(N).

? Space Complexity: O(1) as we are not using any extra space.
*/
pair<pair<int, int>, pair<int, int>> twoSum1(int *a, int n, int k)
{
    map<int, int> hash;
    int temp;

    for (int i = 0; i < n; i++)
    {
        temp = k - a[i];
        if (hash.find(temp) != hash.end())
        {
            return {{temp, a[i]}, {hash[temp], i}};
        }
        hash[a[i]] = i;
    }
    return {{-1, -1}, {-1, -1}};
}

/*
? Time Complexity: O(N).

? Space Complexity: O(1) as we are not using any extra space.

! Works only if the array is sorted
*/
pair<pair<int, int>, pair<int, int>> twoSum2(int *a, int n, int k)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == k)
            return {{a[i], a[j]}, {i, j}};
        else if (sum < k)
            i++;
        else
            j--;
    }

    return {{-1, -1}, {-1, -1}};
}

int main()
{
    int arr[] = {2, 6, 5, 8, 11}, target = 14;
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<pair<int, int>, pair<int, int>> i = twoSum(arr, n, target);
    printf("Pair with Target Sum(Brute-force): {%d, %d} at indexes {%d, %d}\n", i.first.first, i.first.second, i.second.first, i.second.second);
    i = twoSum1(arr, n, target);
    printf("Pair with Target Sum(Better): {%d, %d} at indexes {%d, %d}\n", i.first.first, i.first.second, i.second.first, i.second.second);
    i = twoSum2(arr, n, target);
    printf("Pair with Target Sum(Optimal): {%d, %d} at indexes {%d, %d}\n", i.first.first, i.first.second, i.second.first, i.second.second);
}