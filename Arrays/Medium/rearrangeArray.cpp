#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N) + O(N/2)
*/
void rearrangePosNeg(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos, neg;

    for (auto i : arr)
    {
        if (i > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    arr.erase(arr.begin(), arr.end());

    n = pos.size();

    for (int i = 0; i < n; i++)
    {
        arr.push_back(pos[i]);
        arr.push_back(neg[i]);
    }

    cout << "Brute-force: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(N)
*/
void rearrangePosNeg1(vector<int> arr)
{
    int n = arr.size();

    vector<int> temp(n, 0);

    int posInd = 0, negInd = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[negInd] = arr[i];
            negInd += 2;
        }
        else
        {
            temp[posInd] = arr[i];
            posInd += 2;
        }
    }

    cout << "Optimal: ";
    for (auto i : temp)
        cout << i << " ";
    cout << endl;
}

/*
 ? Time Complexity: O(2*N)
*/
void rearrangePosNeg2(vector<int> arr)
{
    int n = arr.size();

    vector<int> pos, neg;

    for (auto i : arr)
    {
        if (i > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    if (pos.size() < neg.size())
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    cout << "Variant2: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // vector<int> arr = {1, 2, 3, -4, -5, -3, -4};
    vector<int> arr = {1, 2, -4, -5};
    rearrangePosNeg(arr);
    rearrangePosNeg1(arr);
    rearrangePosNeg2(arr);
}