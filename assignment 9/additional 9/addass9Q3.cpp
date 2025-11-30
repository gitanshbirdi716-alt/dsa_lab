#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<pair<int,int>>> adj(N + 1); 
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, K));

    while (!pq.empty()) {
        int curr = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        if (time > dist[curr]) continue;

        for (int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i].first;
            int w = adj[curr][i].second;

            if (dist[curr] + w < dist[next]) {
                dist[next] = dist[curr] + w;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        result = max(result, dist[i]);
    }

    cout << result;
    return 0;
}

