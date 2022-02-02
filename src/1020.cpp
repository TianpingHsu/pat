#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
int postorder[31];
int inorder[31];

struct Node {
    int k;
    Node* l = NULL, *r = NULL;
};

void level_tranversal(Node *root) {
    vector<int> v;
    if (root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            v.push_back(node->k);
            q.pop();
            if (node->l) q.push(node->l);
            if (node->r) q.push(node->r);
        }
    }
    for (size_t i = 0; i < v.size(); i++) {
        printf("%d%c", v[i], i == v.size() - 1? '\n' : ' ');
    }
}

Node* rebuild(int pi, int pj, int ii, int ij) {
    Node* root = NULL;
    if (pi <= pj) {
        root = new Node;
        root->k = postorder[pj];
        int k = ii;
        for (; k < ij; k++) {
            if (inorder[k] == root->k) break;
        }
        int l_len = k - ii;
        root->l = rebuild(pi, pi + l_len - 1, ii, ii + l_len - 1);
        root->r = rebuild(pi + l_len, pj - 1, k + 1, ij);
    }
    return root;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    Node *root = rebuild(0, N - 1, 0, N - 1);
    level_tranversal(root);
}
