#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(2*N)
*/
void moveZeros(vector<int> arr, int n)
{
    // To keep track of number of zeros
    int nZero = 0;
    // Temporary array to store non zeroes
    vector<int> temp;

    for (auto it : arr)
    {
        if (it != 0)
            temp.push_back(it);
    }

    int NonZeros = temp.size();
    nZero = n - NonZeros;

    for (int i = 0; i < NonZeros; i++)
        arr[i] = temp[i];

    for (int i = NonZeros; i < n; i++)
        arr[i] = 0;

    cout << "Brute-force: ";
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}

void moveZeros1(vector<int> arr, int n)
{
    int i, j = -1;

    // Place j to first Zero
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // No Zeros
    if (j == -1)
        return;

    for (i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "Optimal: ";
    for (auto it : arr)
        cout << it << " ";
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();

    moveZeros(arr, n);
    moveZeros1(arr, n);
}