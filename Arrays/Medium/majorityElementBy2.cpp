#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array
 * Input Format: N = 7, nums[] = {2,2,1,1,1,2,2}
 * Result: 2
 * Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.
 */

// ? Time Complexity: O(N^2)
int majorityElement(vector<int> arr)
{
    int cnt, n = arr.size();
    for (auto i : arr)
    {
        cnt = 0;
        for (auto j : arr)
        {
            if (i == j)
                cnt++;
        }

        if (cnt > (n / 2))
        {
            return i;
        }
    }
    return -1;
}

// ? Time Complexity: O(NlogN) + O(N)
// ? Space Complexity: O(N), we use map data structure
int majorityElement1(vector<int> arr)
{
    int n = arr.size();
    map<int, int> freq;

    for (auto i : arr)
        freq[i]++;

    for (auto i : freq)
        if (i.second > (n / 2))
            return i.first;
    return -1;
}

// ? Time Complexity: O(N*logN)
// ! Using unordered_map reduces Time Complexity down to O(N), but very rarely may lead to O(N^2) due to hash collisions.
int majorityElement2(vector<int> arr)
{
    int n = arr.size();
    map<int, int> freq;

    for (auto i : arr)
    {
        freq[i]++;

        if (freq[i] > (n / 2))
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << "The majority element is(Brute-force): " << majorityElement(arr) << endl;
    cout << "The majority element is(Better-approach): " << majorityElement1(arr) << endl;
    cout << "The majority element is(Optimal): " << majorityElement2(arr) << endl;
    return 0;
}