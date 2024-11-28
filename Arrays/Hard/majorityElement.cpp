#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * Problem Statement: Given an array of N integers.
 * Find the elements that appear more than N/k times in the array. If no such element exists, return an empty vector.
 */

/*
 ? Time Complexity: O(NlogN)
*/
void majorityElement(vector<int> arr, int n, int k)
{
    // Maximum number of elements with frequency more than N/k
    int ansNum = k - 1;

    // Minimum freq to satisfy condition > N/k
    int ansReq = (int)(n / k) + 1;

    // Vector to store answer
    vector<int> ans;

    // Map to store freq
    map<int, int> freq;

    for (auto i : arr)
    {
        freq[i]++;

        if (freq[i] == ansReq)
        {
            ans.push_back(i);
            if (ans.size() == ansNum)
                break;
        }
    }

    cout << "Elements with freq greater than N/k: ";
    if (ans.size() == 0)
    {
        cout << "No elements";
        return;
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    int n = arr.size();
    int k = 2;

    majorityElement(arr, n, k);
}