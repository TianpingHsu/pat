#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_SIZE = 512, INFINITY = 999999;
int N, M, S, D;
int dis[MAX_SIZE], pre[MAX_SIZE], cost[MAX_SIZE];
struct Edge {
    int s, t, d, c;
};
vector<Edge> vs[MAX_SIZE];

bool bellman_ford(int s) {
    dis[s] = 0, cost[s] = 0;
    for (int i = 0; i < N; i++) {

        for (int u = 0; u < N; u++) {
            for (size_t j = 0; j < vs[u].size(); j++) {
                int v = vs[u][j].t, d = vs[u][j].d, c = vs[u][j].c;
                if (dis[v] > dis[u] + d) {
                    dis[v] = dis[u] + d;
                    pre[v] = u;
                    cost[v] = cost[u] + c;
                } else if (dis[v] == dis[u] + d) {
                    if (cost[v] > cost[u] + c) {
                        pre[v] = u;
                        cost[v] = cost[u] + c;
                    }
                }
            }
        }

    }
    return false;
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

    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0, c1, c2, d, c; i < M; i++) {
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        vs[c1].push_back({c1, c2, d, c});
        vs[c2].push_back({c2, c1, d, c});
    }
    bellman_ford(S);
    dfs(D);
    std::reverse(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("%d %d\n", dis[D], cost[D]);
}
