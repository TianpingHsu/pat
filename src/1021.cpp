#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int N;
const int MAX_SIZE = 10010;
vector<int> nodes[MAX_SIZE];
bool vis[MAX_SIZE];

int dfs(int s, int len) {
    vis[s] = true;
    int current = len;
    for (size_t i = 0; i < nodes[s].size(); i++) {
        if (!vis[nodes[s][i]]) {
            int tmp = dfs(nodes[s][i], len + 1);
            if (tmp > current) current = tmp;
        }
    }
    return current;
}

int main() {
    memset(vis, 0, sizeof(bool) * MAX_SIZE);
    scanf("%d", &N);
    for (int i = 1, x, y; i < N; i++) {
        scanf("%d %d", &x, &y);
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    int k = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            k++;
            dfs(i, 0);
        }
    }
    if (k != 1) {
        printf("Error: %d components\n", k);
    } else {
        set<int> result;        
        int depth = 0;
        for (int i = 1; i <= N; i++) {
            memset(vis, 0, sizeof(bool) * MAX_SIZE);
            int len = dfs(i, 0);
            if (depth == len) {
                result.insert(i);
            } else if (depth < len) {
                depth = len;
                result.clear();
                result.insert(i);
            }
        }
        for (auto x : result) {
            printf("%d\n", x);
        }
    }
}
