#include <iostream>
#include <vector>
using namespace std;

/*
 ! Space Complexity: O(N). Reason: Recursive Stack Call.
*/
void insertionSort(vector<int> &arr, int i, int n)
{
    if (i == n)
    {
        return;
    }

    int j = i - 1;
    int key = arr[i];

    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    insertionSort(arr, i + 1, n);
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    insertionSort(arr, 1, arr.size());
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}