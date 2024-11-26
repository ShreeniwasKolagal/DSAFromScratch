#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a, int n)
{
    int mini;

    for (int i = 0; i < n - 1; i++)
    {
        mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
        }
        int temp = a[i];
        a[i] = a[mini];
        a[mini] = temp;
    }
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    selectionSort(arr, n);

    cout << "After Using selection sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}