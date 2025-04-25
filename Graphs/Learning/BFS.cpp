#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;

    q.push(0);
    vector<int> bfs;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

void addEdge(vector<int> adj[], int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

int main()
{
    int v = 5;
    // cout << "Enter number of Vertices: ";
    // cin >> v;

    vector<int> adj[v+1];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector <int> ans = bfsOfGraph(v, adj);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}