#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int> arr, int n, int key)
{
    int res = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == key)
        {
            res = i;
            break;
        }
    }
    return res;
}

int lastOccurence1(vector<int> arr, int n, int key)
{
    int res = -1;
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] <= key)
        {
            res = mid;
            left = mid + 1;
        }
        if (arr[mid] > key)
        {
            right = mid - 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int n = arr.size();
    int key = 13;

    cout << "Last Occurence at index: " << lastOccurence(arr, n, key) << endl;
    cout << "Last Occurence at index: " << lastOccurence1(arr, n, key) << endl;
}