#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N;
struct Node {
    int k;
    Node* l = NULL, *r = NULL;
};
const int MAX_SIZE = 32;
int inorder[MAX_SIZE];

int find_min(int s, int t) {
    if (s > t) return -1;
    int min = 999999999, res = -1;
    for (int i = s; i <= t; i++) {
        if (min > inorder[i]) {
            min = inorder[i];
            res = i;
        }
    }
    return res;
}

Node* rebuild(int s, int t) {
    if (s > t) return NULL;
    Node* root = new Node;
    int min_idx = find_min(s, t);
    root->k = inorder[min_idx];
    root->l = rebuild(s, min_idx - 1);
    root->r = rebuild(min_idx + 1, t);
    return root;
}

std::vector<int> result;
void level_tranversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        result.push_back(p->k);
        if (p->l) q.push(p->l);
        if (p->r) q.push(p->r);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    Node* root = rebuild(0, N - 1);
    level_tranversal(root);
    for (size_t i = 0; i < result.size(); i++) {
        printf("%d%c", result[i], i == result.size() - 1? '\n' : ' ');
    }
}

