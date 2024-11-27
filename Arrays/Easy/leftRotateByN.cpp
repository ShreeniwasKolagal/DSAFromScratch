#include <iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int> &arr, int n, int k)
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
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int k = 9;

    leftRotate(arr, n, k);
    cout << "After Rotating for " << k << " times: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}