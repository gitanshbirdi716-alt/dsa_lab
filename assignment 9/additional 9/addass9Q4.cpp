#include <bits/stdc++.h>
using namespace std;

int M, N;

bool isSafe(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    return (x >= 0 && x < M && y >= 0 && y < N && grid[x][y] == 1 && !vis[x][y]);
}

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    vis[x][y] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isSafe(nx, ny, grid, vis)) {
            dfs(nx, ny, grid, vis);
        }
    }
}

int main() {
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(M, vector<int>(N, 0));
    int islands = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                islands++;
                dfs(i, j, grid, vis);
            }
        }
    }

    cout << islands;
    return 0;
}

