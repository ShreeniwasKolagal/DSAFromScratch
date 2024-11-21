#include <iostream>
#include <algorithm>
using namespace std;

void revArray(int *a, int start, int end)
{
    if (start < end)
    {
        swap(a[start], a[end]);
        revArray(a, start + 1, end - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    revArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}