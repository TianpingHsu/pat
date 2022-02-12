#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_VERTICES = 1001;
bool g[MAX_VERTICES][MAX_VERTICES] = {0};
int N, M, K;
int indegrees[MAX_VERTICES], tmpindegrees[MAX_VERTICES];

bool is_toplogical_order(vector<int> &order) {
    memcpy(tmpindegrees, indegrees, sizeof(int) * (N + 1));
    for (size_t i = 0; i < order.size(); i++) {
        if (tmpindegrees[order[i]] == 0) {
            for (int j = 1; j <= N; j++) {
                if (g[order[i]][j]) tmpindegrees[j]--;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    memset(g[0], 0, sizeof(bool) * MAX_VERTICES * MAX_VERTICES);
    memset(indegrees, 0, sizeof(int) * MAX_VERTICES);
    memset(tmpindegrees, 0, sizeof(int) * MAX_VERTICES);
    scanf("%d %d", &N, &M);
    for (int i = 1, a, b; i <= M; i++) {
        scanf("%d %d", &a, &b);
        g[a][b] = true;
        indegrees[b]++;
    }
    scanf("%d", &K);
    vector<int> results;
    for (int i = 0; i < K; i++) {
        vector<int> order;
        for (int j = 1, x; j <= N; j++) {
            scanf("%d", &x);
            order.push_back(x);
        }
        if (!is_toplogical_order(order)) results.push_back(i);
    }
    for (size_t i = 0; i < results.size(); i++) {
        printf("%d%c", results[i], i == results.size() - 1 ? '\n' : ' ');
    }
}
