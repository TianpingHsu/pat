#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_CITIES = 512, INFINITY=0x7fffffff;
int C, N, Spro, M;
int g[MAX_CITIES][MAX_CITIES];
int bikes[MAX_CITIES], dist[MAX_CITIES];
bool vis[MAX_CITIES];
vector<vector<int>> pre(MAX_CITIES, vector<int>());

void sp_dijkstra(int s)
{
    dist[s] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1;
        for (int j = 0, d = INFINITY; j <= N; j++) {
            if (!vis[j] && d > dist[j]) {
                u = j;
                d = dist[j];
            }
        }

        if (u == -1) break;
        
        vis[u] = true;
        for (int v = 0; v <= N; v++) {
            if (!vis[v] && g[u][v] != INFINITY) {
                if (dist[v] > dist[u] + g[u][v]) {
                    dist[v] = dist[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dist[v] == dist[u] + g[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<vector<int>> sps;

void collect_paths(const int v, vector<int> path) {
    path.push_back(v);

    if (!pre[v].size()) {
        sps.push_back(path);
        return;
    }

    for (size_t i = 0; i < pre[v].size(); i++) {
        collect_paths(pre[v][i], path);
    }
}

struct Info {
    vector<int> path;
    int sent;
    int back;
};

vector<Info> infos;

void init()
{
    memset(bikes, 0, sizeof(int) * MAX_CITIES);    
    memset(vis, 0, sizeof(bool) * MAX_CITIES);    
    std::fill(dist, dist + MAX_CITIES, INFINITY);
    std::fill(g[0], g[0] + MAX_CITIES * MAX_CITIES, INFINITY);
}

int main()
{
    init();

    // input
    scanf("%d %d %d %d", &C, &N, &Spro, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &bikes[i]);
    }
    for (int i = 0, ci, cj, t; i < M; i++) {
        scanf("%d %d %d", &ci, &cj, &t);
        g[ci][cj] = t;
        g[cj][ci] = t;
    }

    sp_dijkstra(0);

    collect_paths(Spro, vector<int>());

    for (auto &sp : sps) {
        reverse(sp.begin(), sp.end());
        Info info;
        info.path = sp;
        info.sent = 0;
        info.back = 0;
        for (size_t i = 1; i < sp.size(); i++) {
            if (bikes[sp[i]] > C/2) {
                info.back += bikes[sp[i]] - C/2;
            } else if (bikes[sp[i]] < C/2) {
                int lack = C/2 - bikes[sp[i]];
                if (info.back >= lack) {
                    info.back -= lack;
                } else {
                    info.sent += (lack - info.back);
                    info.back = 0;
                }
            }
        }
        infos.push_back(info);
    }

    int optI = 0, minSent = infos[0].sent, minBack = infos[0].back;
    for (size_t i = 1; i < infos.size(); i++) {
        if (minSent > infos[i].sent) {
            optI = i;
            minSent = infos[i].sent;
            minBack = infos[i].back;
        } else if (minSent == infos[i].sent) {
            if (minBack > infos[i].back) {
                optI = i;
                minBack = infos[i].back;
            }
        }
    }

    printf("%d 0", minSent);
    for (size_t i = 1; i < infos[optI].path.size(); i++) {
        printf("->%d", infos[optI].path[i]);
    }
    printf(" %d\n", minBack);
}
