#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int MAX_SIZE = 32;
struct Node {
    char data[32] = {0};
    int l = -1, r = -1, p = -1;
};
Node nodes[MAX_SIZE];
int N;
string result;
void inorder_tranversal(int root) {
    if (root == -1) return;
    if (nodes[root].l == -1 && nodes[root].r == -1) {
        result += string(nodes[root].data);
        return ;
    }
    result.push_back('(');
    inorder_tranversal(nodes[root].l);
    result += string(nodes[root].data);
    inorder_tranversal(nodes[root].r);
    result.push_back(')');
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%s %d %d", nodes[i].data, 
                &nodes[i].l, &nodes[i].r);
        if (nodes[i].l != -1) {
            nodes[nodes[i].l].p = i;
        }
        if (nodes[i].r != -1) {
            nodes[nodes[i].r].p = i;
        }
    }
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (nodes[i].p == -1) {
            root = i;
            break;
        }
    }
    inorder_tranversal(root);
    if (result.size() == 1) {
        cout << result;
    } else {
        for (int i = 1; i <= (int)result.size() - 2; i++) {
            putchar(result[i]);
        }
    }
}
