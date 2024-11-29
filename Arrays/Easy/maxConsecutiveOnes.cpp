#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int consecutivesOnes(vector<int> a, int n)
{
    int maxi = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt++;
        else
            cnt = 0;

        maxi = max(cnt, maxi);
    }

    return maxi;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0};
    int n = nums.size();

    cout << "Maxmimum Number of Consecutive Ones: " << consecutivesOnes(nums, n) << endl;
}