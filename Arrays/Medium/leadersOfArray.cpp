#include <iostream>
#include <vector>
using namespace std;

void leaders(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    int maxi = arr.back();

    ans.push_back(arr.back());
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    cout << "Leaders in array: ";
    for (auto i : ans)
        cout << i << " ";
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    leaders(arr);
}