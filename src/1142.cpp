#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int MAX_SIZE = 256;
set<int> adj[MAX_SIZE];
int Nv, Ne, M, K;

bool is_clique(const vector<int> &s) {
    for (size_t i = 0; i < s.size(); i++) {
        int u = s[i];
        for (auto v : s) {
            if (u != v && adj[u].find(v) == adj[u].end()) return false;
        }
    }
    return true;
}

bool is_max_clique(const vector<int> &s) {
    set<int> ss(s.begin(), s.end());
    for (int i = 1; i <= Nv; i++) {
        if (ss.find(i) == ss.end()) {
            bool flag = true;
            for (auto u : ss) {
                if (adj[i].find(u) == adj[i].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0, x, y; i < Ne; i++) {
        scanf("%d %d", &x, &y);
        adj[x].insert(y);
        adj[y].insert(x);
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &K);
        int x;
        vector<int> v;
        while (K--) {
            scanf("%d", &x);
            v.push_back(x);
        }
        if (!is_clique(v)) {
            printf("Not a Clique\n");
        } else {
            if (is_max_clique(v)) {
                printf("Yes\n");
            } else {
                printf("Not Maximal\n");
            }
        }
    }
}
