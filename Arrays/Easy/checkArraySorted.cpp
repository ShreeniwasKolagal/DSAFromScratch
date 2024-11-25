#include <iostream>
#include <vector>
using namespace std;

bool checkSort(vector<int> a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Reverse the sign to check for descending order
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 4, 5};

    cout << ((checkSort(arr, arr.size()) == 1) ? "Array is sorted" : "Array is NOT Sorted");
}