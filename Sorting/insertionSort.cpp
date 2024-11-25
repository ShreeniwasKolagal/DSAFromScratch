#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N^2)
 */
void insertionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insert the key at the correct position
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    insertionSort(arr);
}