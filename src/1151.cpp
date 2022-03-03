#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
struct Node {
    int k;
    Node *l = NULL, *r = NULL;
};
int M, N;
const int MAX_SIZE = 10100;
Node nodes[MAX_SIZE];
int inorder[MAX_SIZE], preorder[MAX_SIZE];

Node *rebuild(int lp, int li, int len) {
    if (len <= 0) return NULL;
    Node *root = new Node;
    root->k = preorder[lp];
    int i = li;
    while (inorder[i] != root->k) i++;
    int left = i - li, right = len - left - 1;
    root->l = rebuild(lp + 1, li, left);
    root->r = rebuild(lp + left + 1, i + 1, right);
    return root;
}

// k must in the tree
Node* search(Node* root, int k, std::vector<Node*> &v) {
    if (!root) return NULL;
    if (root->k == k) return root;
    Node *l = search(root->l, k, v);
    if (l) {
        v.push_back(root->l);
        return l;
    }
    Node* r = search(root->r, k, v);
    if (r) v.push_back(root->r);
    return r;
}

int main() {
    scanf("%d %d", &M, &N);
    std::set<int> s;
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
        s.insert(inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    Node *root = rebuild(0, 0, N);
    while (M--) {
        int U, V;
        scanf("%d %d", &U, &V);
        if (s.find(U) == s.end() && 
                s.find(V) == s.end()) {
            printf("ERROR: %d and %d are not found.\n", U, V);
        } else if (s.find(U) == s.end()) {
            printf("ERROR: %d is not found.\n", U);
        } else if (s.find(V) == s.end()) {
            printf("ERROR: %d is not found.\n", V);
        } else {
            std::vector<Node*> path_u, path_v;
            Node *u = search(root, U, path_u);
            Node *v = search(root, V, path_v);
            path_u.push_back(root);
            path_v.push_back(root);
            bool u_v = false, v_u = false;
            for (int i = path_v.size() - 1; i >=0; i--) {
                if (path_v[i] == u) {
                    u_v = true;
                    break;
                }
            }
            if (u_v) {
                printf("%d is an ancestor of %d.\n", U, V);
                continue;
            }
            for (int i = path_u.size() - 1; i >=0; i--) {
                if (path_u[i] == v) {
                    v_u = true;
                    break;
                }
            }
            if (v_u) {
                printf("%d is an ancestor of %d.\n", V, U);
                continue;
            }
            Node *lca = NULL;
            std::reverse(path_u.begin(), path_u.end());
            std::reverse(path_v.begin(), path_v.end());
            for (size_t i = 0; i < path_u.size() && i < path_v.size(); i++) {
                if (path_u[i] != path_v[i]) {
                    lca = path_u[i - 1];
                    break;
                }
            }
            printf("LCA of %d and %d is %d.\n", U, V, lca->k);
        }
    }
}
