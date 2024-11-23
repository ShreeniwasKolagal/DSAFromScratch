#include <iostream>
#include <vector>
using namespace std;

/*
? Time Complexity: O(logN), where N = size of the given array.
? Space Complexity: O(1) as we are using no extra space.
*/
int binarySearch(vector<int> a, int k)
{
    int n = a.size();
    int left = 0, right = n - 1, mid = n / 2;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearch1(vector<int> a, int k, int left, int right)
{
    if (right < left)
        return -1;

    int mid = (left + right) / 2;

    if (a[mid] == k)
        return mid;
    else if (a[mid] < k)
        return binarySearch1(a, k, mid + 1, right);
    else
        return binarySearch1(a, k, left, mid - 1);
}

int main()
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    int i = binarySearch(arr, target);
    if (i == -1)
        cout << "The target is not present." << endl;
    else
        cout << "Target is at index(Iterative): " << i << endl;

    i = binarySearch1(arr, target, 0, arr.size() - 1);
    if (i == -1)
        cout << "The target is not present." << endl;
    else
        cout << "Target is at index(Recursive): " << i << endl;
}