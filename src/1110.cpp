#include <cstdio>
#include <queue>
using namespace std;

const int MAX_N = 20;
int N;
struct Node {
    Node* p = NULL, *l = NULL, *r = NULL;
    int level = 0, idx = 0;
};
Node tree[MAX_N];

Node* heap[0x01 << 20] = {NULL};

void tranversal(Node* root, int k) {
    if (root) heap[k] = root;
    if (root->l) {
        heap[2 * k] = root->l;
        tranversal(root->l, 2 * k);
    }
    if (root->r) {
        heap[2 * k + 1] = root->r;
        tranversal(root->r, 2 * k + 1);
    }
}

int first_null = -1, last_leaf = -1;
bool is_complete_bt(Node* root) {
    tranversal(root, 1);
    for (int i = 1; i <= N; i++) {
        if (!heap[i] && first_null == -1) first_null = i;
        if (heap[i]) last_leaf = i;
    }
    return first_null == -1;
}

int to_int(char *s) {
    int sum = 0;
    while (*s) {
        sum *= 10;
        sum += *s++ - '0';
    }
    return sum;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char l[4], r[4];
        tree[i].idx = i;
        scanf(" %s %s", l, r);
        if (l[0] != '-') {
            int x = to_int(l);
            tree[i].l = &tree[x];
            tree[x].p = &tree[i];
        }
        if (r[0] != '-') {
            int x = to_int(r);
            tree[i].r = &tree[x];
            tree[x].p = &tree[i];
        }
    }
    Node *root = tree;
    while (root->p) {root++;}
    bool res = is_complete_bt(root);
    if (res) {
        printf("YES %d\n", heap[last_leaf]->idx);
    } else {
        printf("NO %d\n", root->idx);
    }
}

