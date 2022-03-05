#include <cstdio>
#include <algorithm>
struct Node {
    int k, h = 1;
    Node *l = NULL, *r = NULL;
};

int height(Node* root) {
    if (!root) return 0;
    return root->h;
}

int update_height(Node *root) {
    if (!root) return 0;
    return root->h = std::max(height(root->l), height(root->r)) + 1;
}

Node* right_rotate(Node *x) {
    // x(root) is the first unbalanced node
    /*
            x                       y
           /                       / \
          y         ->            z   x
         / \                         /
        z   w                       w
     */
    Node *y = x->l, *z = y->l;
    x->l = y->r, y->l = z, y->r = x;
    update_height(z), update_height(x), update_height(y);
    return y;
}

Node* left_rotate(Node *x) {
    Node *y = x->r, *z = y->r;
    x->r = y->l, y->r = z, y->l = x;
    update_height(z), update_height(x), update_height(y);
    return y;
}

Node *LR_rotate(Node *x) {
    /*
            x                 x                 z
           /                 /                 / \
          y         ->      z        ->       y   x
           \               /
            z             y
     */
    Node *y = x->l;
    x->l = left_rotate(y);
    return right_rotate(x);
}

Node *RL_rotate(Node *x) {
    Node *y = x->r;
    x->r = right_rotate(y);
    return left_rotate(x);
}

Node *insert(Node *root, int k) {
    if (!root) {
        root = new Node;
        root->k = k;
    } else {
        if (k < root->k) {  // go left
            root->l = insert(root->l, k);
            if (height(root->l) - height(root->r) == 2) {
                if (k < root->l->k) {  // ll
                    root = right_rotate(root);                    
                } else {  // lr
                    root = LR_rotate(root);
                }
            }
        } else {
            root->r = insert(root->r, k);
            if (height(root->r) - height(root->l) == 2) {  // go right
                if (k >= root->r->k) {  // rr
                    root = left_rotate(root);
                } else {  // rl
                    root = RL_rotate(root);
                }
            }
        }
    }
    update_height(root);
    return root;
}

int main() {
    int N;
    scanf("%d", &N);
    Node *root = NULL;
    for (int i = 0, k; i < N; i++) {
        scanf("%d", &k);
        root = insert(root, k);
        //printf("\nafter insert %d: root: %d\n", k, root->k);
    }
    printf("%d", root->k);
}
