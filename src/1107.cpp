#include <cstdio>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_SIZE = 1024;
int g[MAX_SIZE][MAX_SIZE], N, K, H = 0;
bool vis[MAX_SIZE];

void search(int u, set<int> &s) {
    vis[u] = true;
    s.insert(u);
    for (int i = 1; i <= H; i++) {
        if (g[u][i]) {
            for (int j = 1; j <= N; j++) {
                if (!vis[j] && g[j][i]) {
                    search(j, s);
                }
            }
        }
    }
}

int main() {
    memset(g[0], 0, sizeof(int) * MAX_SIZE * MAX_SIZE);
    memset(vis, 0, sizeof(bool) * MAX_SIZE);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d:", &K);
        for (int j = 1, x; j <= K; j++) {
            scanf("%d", &x);
            if (H < x) H = x;
            g[i][x] = 1;
        }
    }
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        set<int> s;
        if (!vis[i]) {
            search(i, s);
            result.push_back(s.size());
        }
    }
    sort(result.begin(), result.end(), greater<unsigned int>());
    printf("%lu\n", result.size());
    for (size_t i = 0; i < result.size(); i++) {
        printf("%d%c", result[i], i == result.size() - 1 ? '\n' : ' ');
    }
}
