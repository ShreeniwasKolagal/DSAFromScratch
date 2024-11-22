#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(N*log(N))

Space Complexity: O(n)
*/
int maxElement(vector<int> &a)
{
    // We sort the array, then the largest element is at last index
    sort(a.begin(), a.end());
    return a[a.size() - 1];
}
int maxElement1(vector<int> &a)
{
    // Variable to store max element
    int maxL = INT16_MIN;

    for (auto item : a)
    {
        // If item greater, update the variable
        maxL = max(item, maxL);
    }
    return maxL;
}

int main()
{
    vector<int> arr = {2, 5, 1, 3, 0};

    cout << "Largest Element in Array (Brute-force): " << maxElement(arr) << endl;
    cout << "Largest Element in Array (Optimal): " << maxElement1(arr) << endl;
}