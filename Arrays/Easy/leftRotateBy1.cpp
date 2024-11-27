#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(N)
*/
void leftRotate(vector<int> arr, int n)
{
    vector<int> temp;

    for (int i = 1; i < n; i++)
        temp.push_back(arr[i]);

    temp.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(1)
*/
void leftRotate1(vector<int> arr, int n)
{
    int temp = arr.front();
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    leftRotate(arr, arr.size());
    leftRotate1(arr, arr.size());
}