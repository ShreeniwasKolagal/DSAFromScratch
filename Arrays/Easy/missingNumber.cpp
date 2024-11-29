#include <iostream>
#include <vector>
using namespace std;

/*
 ? Time Complexity: O(N^2)
*/
void missingNumber(vector<int> a, int N)
{
    int flag = 0;
    for (int i = 1; i <= N; i++)
    {
        flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "Missing Number(Brute-force): " << i << endl;
            return;
        }
    }
}

/*
 ? Time Complexity: O(2*N)
*/
void missingNumber1(vector<int> a, int N)
{
    int hash[N + 1] = {0};

    for (int i = 0; i < N - 1; i++)
    {
        hash[a[i]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            cout << "Missing Number(Hash Approach): " << i << endl;
            return;
        }
    }
}

/*
 ? Time Complexity: O(N)
*/
void missingNumber2(vector<int> a, int N)
{
    // Sum till N numbers
    int Sum1 = (N * (N + 1)) / 2;

    int Sum2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        Sum2 += a[i];
    }

    cout << "Missin Number(Sum Approach): " << Sum1 - Sum2 << endl;
}

/*
 ? Time Complexity: O(N)
*/
void missingNumber3(vector<int> a, int N)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 ^= a[i];    // Xor of all array elements
        xor1 ^= (i + 1); // xor of [1...N-1]
    }
    xor1 ^= N;

    cout << "Missing Number(XOR Approach): " << (xor1 ^ xor2);
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};

    missingNumber(a, N);
    missingNumber1(a, N);
    missingNumber2(a, N);
    missingNumber3(a, N);
}