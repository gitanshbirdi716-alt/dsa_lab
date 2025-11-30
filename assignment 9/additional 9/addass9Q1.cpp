#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);   
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);      
    }

    vector<int> vis(V, 0);
    int components = 0;

    for (int start = 0; start < V; start++) {
        if (!vis[start]) {
            components++;       
            queue<int> q;
            q.push(start);
            vis[start] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << components;
    return 0;
}

