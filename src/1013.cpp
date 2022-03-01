#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int N, M, K;
const int MAX_SIZE = 1001;
int g[MAX_SIZE][MAX_SIZE];
bool vis[MAX_SIZE];

void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i <= N; i++) {
        if (!vis[i] && g[u][i]) dfs(i);
    }
}

int repair(int city) {
    vector<int> adj;
    for (int i = 1; i <= N; i++) {
        if (g[city][i]) {
            adj.push_back(i);
            g[city][i] = 0;
            g[i][city] = 0;
        }
    }

    memset(vis, 0, sizeof(bool) * MAX_SIZE);
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }

    for (size_t i = 0; i < adj.size(); i++) {
        g[city][adj[i]] = 1;
        g[adj[i]][city] = 1;
    }
    return count;
}

int main() {
    memset(g[0], 0, sizeof(int) * MAX_SIZE * MAX_SIZE);
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0, x, y; i < M; i++) {
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
        g[y][x] = 1;
    }
    for (int i = 0, city; i < K; i++) {
        scanf("%d", &city);
        printf("%d\n", repair(city) - 2);
    }
}

