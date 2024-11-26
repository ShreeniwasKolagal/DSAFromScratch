#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array
 */

// Using sorting techniques,
void sortArray(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    cout << "Sorting: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

/*
 ? Time Complexity: O(N) + O(N)
*/
void sortArray1(vector<int> arr, int n)
{
    // Store number of 0s, 1s and 2s
    int count[3] = {0, 0, 0};
    for (auto i : arr)
    {
        count[i]++;
    }

    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        while (count[i])
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
    }

    cout << "Sorting by count: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

/*
 ? Time Complexity: O(N)
*/
void sortArray2(vector<int> arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++, mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    cout << "Sorting by Dutch National Flag Algorithm: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};

    sortArray(arr, arr.size());
    sortArray1(arr, arr.size());
    sortArray2(arr, arr.size());
}