#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE=1024;
int N, M, K, D;  // 1...N, N+1 ... N+M
unsigned int g[MAX_SIZE][MAX_SIZE];
struct Info {
    unsigned int minimum_d = -1;
    int u = 99999;
    double average;
};
vector<Info> result;

void sp(int s) {
    unsigned int dis[MAX_SIZE], vis[MAX_SIZE];
    memset(dis, -1, sizeof(unsigned int) * MAX_SIZE);
    memset(vis, 0, sizeof(unsigned int) * MAX_SIZE);
    dis[s] = 0;
    for (int i = 1; i <= N + M; i++) {
        int u = -1;
        unsigned int min_d = -1;
        for (int v = 1; v <= N + M; v++) {
            if (!vis[v] && min_d > dis[v]) {
                u = v;
                min_d = dis[v];
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (int v = 1; v <= N + M; v++) {
            if (!vis[v] && g[u][v] != (unsigned int)-1) {
                if (dis[v] > dis[u] + g[u][v]) {
                    dis[v] = dis[u] + g[u][v];
                }
            }
        }
    }
    bool flag = true;
    double total = 0;
    unsigned int min_dis = (unsigned int)-1;
    for (int i = 1; i <= N; i++) {
        if (dis[i] == (unsigned int)-1) {  // not connected
            flag = false;
            break;
        }
        if (dis[i] > (unsigned int)D) {  // candidate is not satisfied
            flag = false;
            break;
        }
        total += dis[i];
        if (min_dis > dis[i]) {
            min_dis = dis[i];
        }
    }
    if (flag) {
        Info info;
        info.u = s;
        info.minimum_d = min_dis;
        info.average = total / N;
        result.push_back(info);
    }
}

int main() {
    memset(g[0], -1, sizeof(unsigned int) * MAX_SIZE * MAX_SIZE);
    scanf("%d %d %d %d", &N, &M, &K, &D);
    string a, b;
    for (int i = 0, d; i < K; i++) {
        cin >> a >> b >> d;
        int ca, cb;
        string c;
        if (a[0] == 'G') {
            c = a.substr(1);
            ca = stoi(c) + N;
        } else {
            ca = stoi(a);
        }
        if (b[0] == 'G') {
            c = b.substr(1);
            cb = stoi(c) + N;
        } else {
            cb = stoi(b);
        }
        g[ca][cb] = d;
        g[cb][ca] = d;
    }
    for (int i = N + 1; i <= N + M; i++) {
        sp(i);
    }
    if (!result.size()) {
        printf("No Solution\n");
    } else {
        sort(result.begin(), result.end(), [](const Info &a, const Info &b) {
                if (a.minimum_d == b.minimum_d) {
                    if (a.average == b.average) return a.u < b.u;
                    return a.average < b.average;
                }                
                return a.minimum_d > b.minimum_d;
                });
        Info info = result[0];
        printf("G%d\n", info.u - N);
        printf("%.1lf %.1lf\n", (double)info.minimum_d, info.average);
    }
}
