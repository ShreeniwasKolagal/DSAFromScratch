#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
 ? Time Complexity: O(m+n * log(m+n))
 ? Space Complexity: O(m+n)
*/
void findUnion(vector<int> a, vector<int> b, int m, int n)
{
    set<int> s;

    for (auto i : a)
        s.insert(i);

    for (auto i : b)
        s.insert(i);

    cout << "Using Sets: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

/*
 ? Time Complexity: O(m+n)
 ? Space Complexity: O(m+n)
*/
void findUnion1(vector<int> a, vector<int> b, int m, int n)
{
    vector<int> unionSet;

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            if (unionSet.size() == 0 || unionSet.back() != a[i])
                unionSet.push_back(a[i]);
            i++;
        }
        else
        {
            if (unionSet.size() == 0 || unionSet.back() != b[j])
                unionSet.push_back(b[j]);
            j++;
        }
    }

    while (i < m)
    {
        if (unionSet.size() == 0 || unionSet.back() != a[i])
            unionSet.push_back(a[i]);
        i++;
    }

    while (j < n)
    {
        if (unionSet.size() == 0 || unionSet.back() != b[j])
            unionSet.push_back(b[j]);
        j++;
    }

    cout << "Two-pointer Approach: ";
    for (auto i : unionSet)
        cout << i << " ";
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    int m = arr1.size(), n = arr2.size();

    findUnion(arr1, arr2, m, n);
    findUnion1(arr1, arr2, m, n);
}