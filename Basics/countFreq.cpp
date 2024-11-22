#include <iostream>
#include <map>
using namespace std;

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (auto a : freq)
        cout << a.first << " : " << a.second << endl;
}