#include <iostream>
#include <map>
using namespace std;

void countFreq(int *a, int n)
{
    int maxf = 0;
    int minf = INT16_MAX;
    int maxele = 0;
    int minele = INT16_MAX;

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    for (auto i : freq)
    {
        if (i.second > maxf)
        {
            maxf = i.second;
            maxele = i.first;
        }
        if (i.second < minf)
        {
            minf = i.second;
            minele = i.first;
        }
    }

    cout << "Max: " << maxele << endl;
    cout << "Min: " << minele << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}