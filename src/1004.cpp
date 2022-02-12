#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 128;
struct Node {
    Node *p = NULL;
    vector<Node*> childs;
    int idx = 0, level = 0;
};

Node tree[MAX_N];
int results[MAX_N] = {0};

int N, M, deepest = 0;
void tranversal(int root, int level) {
    if (root > N) return;    
    tree[root].level = level;
    if (level > deepest) deepest = level;
    for (size_t i = 0; i < tree[root].childs.size(); i++) {
        Node* child = tree[root].childs[i];
        tranversal(child->idx, level + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    if (N == 0) return 0;
    for (int i = 0; i < M; i++) {
        int id, k, child;
        scanf("%d %d", &id, &k);
        tree[id].idx = id;
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            tree[id].childs.push_back(&tree[child]);
            tree[child].p = &tree[id];
            tree[child].idx = child;
        }
    }
    
    tranversal(1, 1);
    for (int i = 1; i <= N; i++) {
        if (tree[i].childs.empty())
            results[tree[i].level]++;
    }

    for (int i = 1; i <= deepest; i++) {
        printf("%d%c", results[i], i == deepest ? '\n' : ' ');
    }
    return 0;
}
