#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], vector<int>& ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int start = 0;

    // vector to store dfs
    vector<int> ls;

    dfs(start, vis, adj, ls);

    return ls;
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

    vector<int> adj[v + 1];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector<int> ans = dfsOfGraph(v, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}