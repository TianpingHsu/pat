#include <cstdio>
#include <cstring>

const int MAX_SIZE = 1005;
int Nv, Ne, K;
unsigned int g[MAX_SIZE][MAX_SIZE];
unsigned int INFINITY = -1;
unsigned int order[MAX_SIZE];
unsigned int dis[MAX_SIZE];
bool vis[MAX_SIZE];

bool is_dijkstra_seq() {
    memset(dis, -1, sizeof(unsigned int) * MAX_SIZE);
    memset(vis, 0, sizeof(bool) * MAX_SIZE);
    int k = 0;
    dis[order[k]] = 0;
    for (int i = 0; i < Nv; i++) {
        unsigned int u = MAX_SIZE, min = INFINITY;
        for (int v = 1; v <= Nv; v++) {
            if (!vis[v] && min > dis[v]) {
                    min = dis[v];
                    u = v;
            }
        }
        if (u == MAX_SIZE) {
            break;
        } else {
            if (min != dis[order[k]]) {
                return false;
            } else {
                u = order[k++];
                vis[u] = true;
                for (int t = 1; t <= Nv; t++) {
                    if (!vis[t] && g[u][t] != INFINITY) {
                        if (dis[t] > dis[u] + g[u][t]) {
                            dis[t] = dis[u] + g[u][t];
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    memset(g[0], -1, sizeof(unsigned int) * MAX_SIZE * MAX_SIZE);
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0,a,b,e; i < Ne; i++) {
        scanf("%d %d %d", &a, &b, &e);
        g[a][b] = e;
        g[b][a] = e;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < Nv; j++) {
            scanf("%d", &order[j]);
        }
        if (is_dijkstra_seq()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
