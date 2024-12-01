#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation:
 * Buy on day 2 (price = 1)
 * sell on day 5 (price = 6), profit = 6-1 = 5.
 */

/*
 ? Time Complexity: O(2*N)
*/
void maxProfit(vector<int> arr, int n)
{
    int maxPro = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(maxPro, arr[j] - arr[i]);
            }
        }
    }

    cout << "Max Profit(Brute-force): " << maxPro << endl;
}

/*
 ? Time Complexity: O(N)
*/
void maxProfit1(vector<int> arr, int n)
{
    int maxPro = 0, minPrice = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    cout << "Max Profit(Optimal): " << maxPro << endl;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int n = arr.size();

    maxProfit(arr, n);
    maxProfit1(arr, n);
}