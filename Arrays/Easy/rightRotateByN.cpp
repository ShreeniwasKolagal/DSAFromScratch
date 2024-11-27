#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(K)
*/
void rightRotate(vector<int> arr, int n, int k)
{
    vector<int> temp;

    k = k % n;

    for (int i = n - k; i < n; i++)
        temp.push_back(arr[i]);

    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }

    for (int i = 0; i < k; i++)
        arr[i] = temp[i];

    cout << "After Rotating for " << k << " times: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(1)
*/
void reverse(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++, end--;
    }
}
void rightRotate1(vector<int> arr, int n, int k)
{
    k = k % n;

    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - 1);

    cout << "After Rotating for " << k << " times: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int k = 2;

    rightRotate(arr, n, k);
    rightRotate1(arr, n, k);
}