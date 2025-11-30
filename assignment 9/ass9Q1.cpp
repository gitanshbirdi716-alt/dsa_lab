#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) parent[x] = y;
        else if (rank[y] < rank[x]) parent[y] = x;
        else { parent[y] = x; rank[x]++; }
        return true;
    }
};
class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj; 
    vector<Edge> edges;               
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); 
        Edge e = {u, v, w};
        edges.push_back(e);
    }
    void BFS(int start) {
        vector<int> vis(V, 0);
        queue<int> q;
        vis[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }
    void dfsUtil(int u, vector<int> &vis) {
        vis[u] = 1;
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (!vis[v]) dfsUtil(v, vis);
        }
    }
    void DFS(int start) {
        vector<int> vis(V, 0);
        cout << "DFS Traversal: ";
        dfsUtil(start, vis);
        cout << "\n";
    }

    void Kruskal() {
        DSU dsu(V);
        sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

        int mstCost = 0;
        cout << "Kruskal MST Edges:\n";
        for (int i = 0; i < edges.size(); i++) {
            if (dsu.unite(edges[i].u, edges[i].v)) {
                mstCost += edges[i].w;
                cout << edges[i].u << " - " << edges[i].v << " (cost " << edges[i].w << ")\n";
            }
        }
        cout << "Total MST Cost (Kruskal): " << mstCost << "\n";
    }

    void Prim(int start) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<int> inMST(V, 0);

        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int j = 0; j < V; j++)
                if (!inMST[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;

            inMST[u] = 1;

            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].first;
                int w = adj[u][j].second;
                if (!inMST[v] && w < dist[v]) {
                    dist[v] = w;
                    parent[v] = u;
                }
            }
        }

        int total = 0;
        cout << "Prim MST Edges:\n";
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << " (cost " << dist[i] << ")\n";
                total += dist[i];
            }
        }
        cout << "Total MST Cost (Prim): " << total << "\n";
    }

    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (cost > dist[u]) continue;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Dijkstra Distances from node " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;
    Graph g(V);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int choice, start;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. BFS\n2. DFS\n3. MST (Kruskal)\n4. MST (Prim)\n5. Dijkstra\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 6) break;

        if (choice == 1 || choice == 2 || choice == 5) {
            cout << "Enter start vertex: ";
            cin >> start;
        }

        switch(choice) {
            case 1: g.BFS(start); break;
            case 2: g.DFS(start); break;
            case 3: g.Kruskal(); break;
            case 4: g.Prim(0); break;
            case 5: g.Dijkstra(start); break;
            default: cout << "Invalid choice\n";
        }
    }
    return 0;
}

