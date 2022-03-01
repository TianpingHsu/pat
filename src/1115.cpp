#include <cstdio>
struct Node {
    int k, level = 0;
    Node* l = NULL, *r = NULL;
};

int N;
Node* root = NULL;

void insert(int k) {
    if (!root) {
        root = new Node;
        root->k = k;
        return ;
    }
    Node* p = root, *q = p;
    while (p) {
        q = p;
        if (k <= p->k) {
            p = p->l;
        } else {
            p = p->r;
        }
    }
    Node* t = new Node;
    t->k = k;
    if (k <= q->k) {
        q->l = t;
    } else {
        q->r = t;
    }
    return ;
}

void level_tranversal(Node* root, int level) {
    if (root) {
        root->level = level;
        level_tranversal(root->l, level + 1);
        level_tranversal(root->r, level + 1);
    }
}

int max_level = 0;
void find_max_level(Node* root) {
    if (root) {
        if (root->level > max_level) max_level = root->level;
        find_max_level(root->l);
        find_max_level(root->r);
    }
}

int count_level_nodes(Node* root, int level) {
    if (root) {
        if (root->level == level) return 1;
        return count_level_nodes(root->l, level) + 
            count_level_nodes(root->r, level);
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        insert(x);
    }
    level_tranversal(root, 0);
    find_max_level(root);
    int n1 = count_level_nodes(root, max_level);
    int n2 = count_level_nodes(root, max_level - 1);
    printf("%d + %d = %d\n", n1, n2, n1 + n2);
}

