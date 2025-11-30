#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    priority_queue<
        pair<int, pair<int,int>>, 
        vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>> > pq;

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];
    pq.push(make_pair(grid[0][0], make_pair(0,0)));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        int curr_cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (curr_cost > dist[x][y]) continue;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int new_cost = curr_cost + grid[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push(make_pair(new_cost, make_pair(nx, ny)));
                }
            }
        }
    }

    cout << dist[m-1][n-1];
    return 0;
}

