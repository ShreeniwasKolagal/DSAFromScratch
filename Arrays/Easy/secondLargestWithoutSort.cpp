#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(NlogN) For sorting array
 ? Space Complexity: O(1)
*/
int secondLarge(vector<int> &a)
{
    // Sort the array. Second largest element is at last but one index
    // ! NOTE: Only works if array has no duplicates
    sort(a.begin(), a.end());
    return a[a.size() - 2];
}

/*
 ? Time Complexity: O(2*N) For linear traversal array
 ? Space Complexity: O(1)
*/
int secondLarge1(vector<int> &a)
{
    int largest = a.front();
    int slargest = INT16_MIN;

    for (auto i : a)
    {
        // Find largest element
        largest = max(largest, i);
    }

    for (auto i : a)
    {
        // Find second largest element
        if (i < largest)
            slargest = max(i, slargest);
    }

    return slargest;
}

/*
 ? Time Complexity: O(N) For linear traversal array
 ? Space Complexity: O(1)
*/
int secondLarge2(vector<int> &a)
{
    int largest = INT16_MIN;
    int slargest = INT16_MIN;

    for (auto i : a)
    {
        if (i > largest)
        {
            // Assign previously largest to slargest
            slargest = largest;
            largest = i;
        }
    }
    return slargest;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 7, 5};

    cout << "Second largest element(Brute-force): " << secondLarge(arr) << endl;
    cout << "Second largest element(Better): " << secondLarge1(arr) << endl;
    cout << "Second largest element(Optimal): " << secondLarge2(arr) << endl;
}