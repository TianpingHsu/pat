#include <cstdio>
#include <cstring>

const int MAX_CITIES = 500, INFINITY=0x7fffffff;
int N, M, C1, C2;
int paths[MAX_CITIES], teams[MAX_CITIES];
unsigned int dist[MAX_CITIES], weight_teams[MAX_CITIES];
bool vis[MAX_CITIES];
int g[MAX_CITIES][MAX_CITIES];

// shortest path
void sp_dijkstra(int s)
{
    dist[s] = 0;
    paths[s] = 1;
    weight_teams[s] = teams[s];
    for (int i = 0; i < N; i++) {

        // find minimal dist of current iteration
        int u = -1;
        for (int j = 0, d = INFINITY; j < N; j++) {
            if ((unsigned int)d > dist[j] && !vis[j]) {
                d = dist[j];
                u = j;
            }
        }

        // check
        if (u != -1) {
            s = u;
        } else {
            break;
        }

        // relaxation
        vis[s] = true;
        for (int v = 0; v < N; v++) {
            if (g[s][v] && !vis[v]) {
                if (dist[v] > dist[s] + g[s][v]) {
                    dist[v] = dist[s] + g[s][v];
                    paths[v] = paths[s];
                    weight_teams[v] = weight_teams[s] + teams[v];
                } else if (dist[v] == dist[s] + g[s][v]) {
                    paths[v] += paths[s];
                    if (weight_teams[v] < weight_teams[s] + teams[v]) {
                        weight_teams[v] = weight_teams[s] + teams[v];
                    }
                }
            }
        }
    }
}

int main()
{
    // init
    memset(g, 0, sizeof(int) * MAX_CITIES * MAX_CITIES);
    memset(vis, 0, sizeof(bool) * MAX_CITIES);
    memset(paths, 0, sizeof(int) * MAX_CITIES);
    memset(teams, 0, sizeof(int) * MAX_CITIES);
    memset(weight_teams, 0, sizeof(int) * MAX_CITIES);
    memset(dist, -1, sizeof(unsigned int) * MAX_CITIES);

    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for (int  i = 0; i < N; i++) {
        scanf("%d", &teams[i]);
    }
    for (int i = 0; i < M; i++) {
        int c1, c2, len;
        scanf("%d %d %d", &c1, &c2, &len);
        g[c1][c2] = len;
        g[c2][c1] = len;
    }
    sp_dijkstra(C1);
    printf("%d %d\n", paths[C2], weight_teams[C2]);
}
