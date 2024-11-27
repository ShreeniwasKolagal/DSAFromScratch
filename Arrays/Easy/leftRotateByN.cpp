#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(K)
*/
void leftRotate(vector<int> arr, int n, int k)
{
    vector<int> temp;

    k = k % n;

    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = 0; i < n - k; i++)
        arr[i] = arr[i + k];

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }

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

void leftRotate1(vector<int> arr, int n, int k)
{
    k = k % n;

    // Reverse first k elements
    reverse(arr, 0, k - 1);
    // Reverse rest of the elements
    reverse(arr, k, n - 1);
    // Reverse entire array
    reverse(arr, 0, n - 1);

    cout << "After Rotating for " << k << " times: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int k = 2;

    leftRotate(arr, n, k);
    leftRotate1(arr, n, k);
}