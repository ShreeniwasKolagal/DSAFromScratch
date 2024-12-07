#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool linearSearch(vector<int> a, int target)
{
    for (auto i : a)
    {
        if (i == target)
            return true;
    }
    return false;
}
/*
 ? Time Complexity: O(N^2)
*/
void longestConsecutive(vector<int> arr, int n)
{
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        // Pick a element
        int x = arr[i];
        int cnt = 1;

        // Find its consecutive numbers
        while (linearSearch(arr, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }

    cout << "Length of longest consecutive sequence: " << longest << endl;
}

/*
 ? Time Complexity: O(NlogN) + O(N)
*/
void longestConsecutive1(vector<int> arr, int n)
{
    // Sort the array
    sort(arr.begin(), arr.end());
    // Store last smallest number
    int lastSmall = INT16_MIN;
    int longest = 1;
    int cnt = 0;

    for (auto i : arr)
    {
        if (i - 1 == lastSmall)
        {
            cnt++;
            lastSmall = i;
        }
        else if (i != lastSmall)
        {
            cnt = 1;
            lastSmall = i;
        }
        longest = max(longest, cnt);
    }

    cout << "Length of longest consecutive sequence: " << longest << endl;
}

/*
 ? Time Complexity: O(3*N)
*/
void longestConsecutive2(vector<int> arr, int n)
{
    int longest = 1;
    unordered_set<int> st;

    for (auto i : arr)
        st.insert(i);

    for (auto i : st)
    {
        // If preceeding number is already present, skip it. Because we already take count of it inside this condition
        if (st.find(i - 1) == st.end())
        {
            int cnt = 1;
            int x = i;

            // Find count of consecutive numbers
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    cout << "Length of longest consecutive sequence: " << longest << endl;
}

int main()
{
    vector<int> arr = {100, 200, 0, 1, 2, 3, 4};
    int n = arr.size();

    longestConsecutive(arr, n);
    longestConsecutive1(arr, n);
    longestConsecutive2(arr, n);
}