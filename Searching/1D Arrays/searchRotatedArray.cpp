#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N)
*/
void searchRotatedArray(vector<int> arr, int n, int target)
{
    for (auto i : arr)
    {
        if (i == target)
        {
            cout << "Found" << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}

/*
 ? TIme Complexity: O(N/2) for worst case. O(logN) for best and average case
*/
void searchRotatedArray1(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            cout << "Found" << endl;
            return;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        // If left part is sorted
        if (arr[low] < arr[mid])
        {
            if (target >= arr[low] && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // Right part is sorted
        {
            if (target >= arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    cout << "Not Found" << endl;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = arr.size();
    int k = 1;

    searchRotatedArray(arr, n, k);
    searchRotatedArray1(arr, n, k);
}