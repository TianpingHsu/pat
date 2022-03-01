#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int MAX_SIZE = 2048;
int g[MAX_SIZE][MAX_SIZE], N, K, vis[MAX_SIZE], count = 0, d[MAX_SIZE];
map<string, int> id;
map<int, string> name;

void dfs(int u, set<int> &s, int &max_len, int &head) {
    vis[u] = 1;
    s.insert(u);
    if (max_len < d[u]) {
        max_len = d[u];
        head = u;
    }
    for (int i = 0; i < count; i++) {
        if (!vis[i] && g[u][i]) {
            dfs(i, s, max_len, head);
        }
    }    
}

int main() {
    memset(g[0], 0, sizeof(int) * MAX_SIZE * MAX_SIZE);
    memset(vis, 0, sizeof(int) * MAX_SIZE);
    memset(d, 0, sizeof(int) * MAX_SIZE);
    scanf("%d %d", &N, &K);
    string n1, n2;
    for (int i = 0, len; i < N; i++) {
        cin >> n1 >> n2 >> len;
        if (id.find(n1) == id.end()) id[n1] = count++;
        if (id.find(n2) == id.end()) id[n2] = count++;
        name[id[n1]] = n1;
        name[id[n2]] = n2;
        d[id[n1]] += len;
        d[id[n2]] += len;
        g[id[n1]][id[n2]] += len;
        g[id[n2]][id[n1]] += len;
    }
    map<string, int> head_num;
    for (int u = 0; u < count; u++) {
        set<int> s;
        int max_len = 0, head = -1;
        if (!vis[u]) dfs(u, s, max_len, head); 
        if (s.size() > 2) {
            int total = 0;
            for (auto it : s) {
                total += d[it];
            }
            if (total > K * 2)
                head_num[name[head]] = s.size();
        }
    }
    printf("%lu\n", head_num.size());
    for (auto it = head_num.begin(); it != head_num.end();  it++) {
        cout << it->first << " " << it->second << endl;
    }
}
