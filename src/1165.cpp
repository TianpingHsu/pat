#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100010;
struct Node {
    int a = -1, d, n = -1;
};
Node nodes[MAX_SIZE];
vector<Node> l;

int main() {
    int head, N, K;
    scanf("%d %d %d", &head, &N, &K);
    for (int i = 0, a, d, n; i < N; i++) {
        scanf("%d %d %d", &a, &d, &n);
        nodes[a].d = d;
        nodes[a].n = n;
        nodes[a].a = a;
    }
    while (head != -1) {
        l.push_back(nodes[head]);
        head = nodes[head].n;
    }
    size_t i = 0;
    vector<vector<Node>> blocks;
    for (; i < l.size();) {
        vector<Node> v;
        for (int j = 0; j < K && i + j < l.size(); j++) {
            v.push_back(l[i + j]);
        }
        blocks.push_back(v);
        i += K;
    }
    std::reverse(blocks.begin(), blocks.end());
    vector<Node> result;
    for (size_t k = 0; k < blocks.size(); k++) {
        vector<Node> &block = blocks[k];
        for (auto item : block) {
            result.push_back(item);
        }
    }
    //printf("result.size(): %lu\n", result.size());
    i = 0;
    for (; i < result.size() - 1; i++) {
        result[i].n = result[i + 1].a;
    }
    result[i].n = -1;
    for (size_t k = 0; k < result.size(); k++) {
        printf("%05d %d ", result[k].a, result[k].d);
        if (result[k].n == -1) {
            printf("-1");
        } else {
            printf("%05d", result[k].n);
        }
        if (k != result.size() - 1) printf("\n");
    }
}
