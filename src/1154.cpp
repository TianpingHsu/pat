#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
const int MAX_SIZE = 10010;
set<int> adj[MAX_SIZE];
int colors[MAX_SIZE];
int N, M, K;

bool k_coloring() {
    for (int i = 0; i < N; i++) {
        int color = colors[i];
        for (auto u : adj[i]) { if (colors[u] == color) return false; }
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0, x, y; i < M; i++) {
        scanf("%d %d", &x, &y);
        adj[x].insert(y);
        adj[y].insert(x);
    }
    scanf("%d", &K);
    while (K--) {
        set<int> cs;
        for (int i = 0; i < N; i++) {
            scanf("%d", &colors[i]);
            cs.insert(colors[i]);
        }
        if (k_coloring()) {
            printf("%d-coloring\n", (int)cs.size());
        } else {
            printf("No\n");
        }
    }
}
