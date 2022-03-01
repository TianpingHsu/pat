#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1024;
int heap[MAX_SIZE], inorder[MAX_SIZE], N;

int idx = 1;
void inorder_tranversal(int i) {
    if (2 * i <= N)
        inorder_tranversal(2 * i);
    heap[i] = inorder[idx++];
    if (2 * i + 1 <= N)
        inorder_tranversal(2 * i + 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &inorder[i]);
    }
    sort(inorder + 1, inorder + 1 + N);
    inorder_tranversal(1);
    for (int i = 1; i <= N; i++) {
        printf("%d%c", heap[i], i == N ? '\n' : ' ');
    }
}
