#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N^2)
*/
void singleElement(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int v = a[i];
        int cnt = 0;

        for (int j = 0; j < n; j++)
            if (v == a[j])
                cnt++;

        if (cnt == 1)
        {
            cout << "Single Element(Brute-force): " << v << endl;
            return;
        }
    }
}

/*
 ? Time Complexity: O(N*logM) + O(M). M = N/2+1
*/
void singleElement1(vector<int> a, int n)
{
    map<int, int> freq;

    for (auto i : a)
        freq[i]++;

    for (auto i : freq)
        if (i.second != 2)
        {
            cout << "Single Element(Hashing): " << i.first << endl;
            return;
        }
}

/*
 ? Time Complexity: O(N)
*/
void singleElement2(vector<int> a, int n)
{
    int xorr = 0;

    for (auto i : a)
        xorr ^= i;

    cout << "Single Element(XOR): " << xorr << endl;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int n = arr.size();

    singleElement(arr, n);
    singleElement1(arr, n);
    singleElement2(arr, n);
}