#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_SIZE = 512, INFINITY = 999999;
int N, M, S, D;
int dis[MAX_SIZE], pre[MAX_SIZE], cost[MAX_SIZE], vis[MAX_SIZE];
int g_cost[MAX_SIZE][MAX_SIZE], g_dist[MAX_SIZE][MAX_SIZE];

void dijkstra(int s) {
    cost[s] = 0;
    dis[s] = 0;
    for (int i = 0; i < N; i++) {
        int min = INFINITY, u = -1;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && min > dis[v]) {
                min = dis[v];
                u = v;
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && g_dist[u][v] != INFINITY) {
                if (dis[v] > dis[u] + g_dist[u][v]) {
                    dis[v] = dis[u] + g_dist[u][v];
                    cost[v] = cost[u] + g_cost[u][v];
                    pre[v] = u;
                } else if (dis[v] == dis[u] + g_dist[u][v]) {
                    if (cost[v] > cost[u] + g_cost[u][v]) {
                        cost[v] = cost[u] + g_cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

vector<int> result;
void dfs(int d) {
    result.push_back(d);
    if (pre[d] == -1) return;
    dfs(pre[d]);
}

int main() {
    fill(dis, dis + MAX_SIZE, INFINITY);
    memset(pre, -1, sizeof(int) * MAX_SIZE);
    memset(cost, 0, sizeof(int) *MAX_SIZE);
    memset(vis, 0, sizeof(int) * MAX_SIZE);
    fill(g_cost[0], g_cost[0] + MAX_SIZE * MAX_SIZE, INFINITY);
    fill(g_dist[0], g_dist[0] + MAX_SIZE * MAX_SIZE, INFINITY);

    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0, c1, c2, d, c; i < M; i++) {
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        g_dist[c1][c2] = d;
        g_dist[c2][c1] = d;
        g_cost[c1][c2] = c;
        g_cost[c2][c1] = c;
    }
    dijkstra(S);
    dfs(D);
    std::reverse(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("%d %d\n", dis[D], cost[D]);
}
