#include <cstdio>
#include <set>
using namespace std;
const int MAX_SIZE = 10010;
int birds[MAX_SIZE], N, K, Q, max_bird = 0;

int find_father(int i) {
    if (i == birds[i]) return i;
    return birds[i] = find_father(birds[i]);
}

void union_ij(int i, int j) {
    int root_i = find_father(i);
    int root_j = find_father(j);
    if (root_i != root_j) {
        birds[root_i] = birds[root_j];
    }
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) {
        birds[i] = i;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        int last;
        scanf("%d", &last);
        if (max_bird < last) max_bird = last;
        for (int j = 1, current; j < K; j++) {
            scanf("%d", &current);
            if (max_bird < current) max_bird = current;
            union_ij(last, current);
            last = current;
        }
    }
    scanf("%d", &Q);
    set<int> trees;
    for (int i = 1; i <= max_bird; i++) {
        trees.insert(find_father(i));
    }
    printf("%d %d\n", (int)trees.size(), max_bird);
    for (int i = 0, x, y; i < Q; i++) {
        scanf("%d %d", &x, &y);
        if (find_father(x) == find_father(y)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
