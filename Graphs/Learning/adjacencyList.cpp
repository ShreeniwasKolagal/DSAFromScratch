#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v,e;
    cin >> v >> e;

    // Space Complexity: O(2 * e)
    vector<int> adj[v+1];

    for(int i=0; i<e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1); // Remove this for Directed Graph
    }

    for(int i=0; i<=v; i++)
    {
        if(!adj[i].empty())
        {
            cout << "Vertex " << i << ": ";
            for(auto it : adj[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}