#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v,e; // v -> vertices, e -> edges
    cin >> v >> e;

    vector<vector<int>> adj(v+1, vector<int>(v+1, 0));

    for(int i=0; i<e; i++)
    {
        int v1, v2;
        int wt;
        cin >> v1 >> v2;
        cin >> wt;

        adj[v1][v2] = adj[v2][v1] = wt;
    }

    for(int i=0; i<=v; i++)
    {
        for(int j = 0; j<=v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}