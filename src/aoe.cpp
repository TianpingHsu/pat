#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1024;
struct Node {
    int s, t, w;    
};
vector<Node> adj[MAX_SIZE];
int indegree[MAX_SIZE], N, V;
stack<int> rtoporder;
queue<int> toporder;
int ve[MAX_SIZE], vl[MAX_SIZE];

bool toplogical_order() {
    // graph should be DAG
    bool vis[MAX_SIZE];
    memset(vis, 0, sizeof(bool) * MAX_SIZE);
    int count = 0, loop = N;
    while (loop--) {
        for (int i = 1; i <= N; i++) {
            if (!vis[i] && indegree[i] == 0) {
                count++;
                vis[i] = true;
                toporder.push(i);
                rtoporder.push(i);
                for (size_t j = 0; j < adj[i].size(); j++) {
                    indegree[adj[i][j].t]--;
                }
            }
        }
        if (count == N) break;
    }
    return count == N;
}

// 1 ... N
void calc_ve(int s) {
    memset(ve, 0, sizeof(int) * MAX_SIZE);
    while (!toporder.empty()) {
        int u = toporder.front();
        for (auto v : adj[u]) {
            if (ve[v.t] < ve[u] + v.w) {
                ve[v.t] = ve[u] + v.w;
            }
        }
        toporder.pop();
    }
}

void calc_vl(int t) {
    fill(vl, vl + MAX_SIZE, ve[t]);
    while (!rtoporder.empty()) {
        int u = rtoporder.top();
        for (auto v : adj[u]) {
            if (vl[u] > vl[v.t] - v.w) {
                vl[u] = vl[v.t] - v.w;
            }
        }        
        rtoporder.pop();
    }
}

int main() {
    memset(indegree, 0, sizeof(int) * MAX_SIZE);
    scanf("%d %d", &N, &V);
    for (int i = 0; i < V; i++) {
        Node node;
        scanf("%d %d %d", &node.s, &node.t, &node.w);
        adj[node.s].push_back(node);
        indegree[node.t]++;
    }
    if (toplogical_order()) {
        calc_ve(1);
        calc_vl(N);
        printf("critical path len: %d\n", ve[N]);
        // critical path
        for (int i = 1; i <= N; i++) {
            for (size_t j = 0; j < adj[i].size(); j++) {
                int u = i, v = adj[i][j].t;
                if (ve[u] == vl[v] - adj[i][j].w) {
                    printf("%d->%d\n", u, v);
                }
            }
        }
    }
}
