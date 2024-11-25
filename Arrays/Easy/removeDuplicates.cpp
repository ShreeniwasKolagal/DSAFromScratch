#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 ? Time Complexity: O(N) + O(N)
 ! unordered_set can be used by below logic only if the array is sorted.
 ! Else use set O(N*logN)
*/
int removeDuplicates(vector<int> &a, int n)
{
    unordered_set<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(a[i]);
    }

    n = 0;
    for (auto i : s)
    {
        a[n] = i;
        n++;
    }
    return n;
}

/*
 ? Time Complexity: O(N)
*/
int removeDuplicates1(vector<int> &a, int n)
{
    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
    }
    return i + 1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};

    int k = removeDuplicates(arr, arr.size());
    cout << "Brute-force: ";
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    arr = {1, 1, 2, 2, 2, 3, 3};

    k = removeDuplicates1(arr, arr.size());
    cout << "\nTwo-Pointer: ";
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}