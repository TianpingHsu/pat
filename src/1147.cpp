#include <cstdio>
#include <vector>

int N, M;
const int MAX_SIZE = 1001;
int nodes[MAX_SIZE];

bool is_max_heap(int i) {
    if (i > N) return true;
    int l = 2 * i, r = 2 * i + 1;
    if (l > N && r > N) return true;
    if (l <= N && r > N) {
        return nodes[i] >= nodes[l];
    }
    if (l <= N && r <= N) {
        return nodes[i] >= nodes[l] && nodes[i] >= nodes[r] 
            && (is_max_heap(l) && is_max_heap(r));
    }
    return false;
}

bool is_min_heap(int i) {
    if (i > N) return true;
    int l = 2 * i, r = 2 * i + 1;
    if (l > N && r > N) return true;
    if (l <= N && r > N) {
        return nodes[i] <= nodes[l];
    }
    if (l <= N && r <= N) {
        return nodes[i] <= nodes[l] && nodes[i] <= nodes[r] 
            && (is_min_heap(l) && is_min_heap(r));
    }
    return false;
}

int process_it() {
    if (is_max_heap(1)) return 1;
    if (is_min_heap(1)) return -1;
    return 0;
}

std::vector<int> post_order;
void post_tranversal(int i) {
    if (i <= N) {
        post_tranversal(2 * i);
        post_tranversal(2 * i + 1);
        post_order.push_back(nodes[i]);
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &nodes[j]);
        }
        int res = process_it();
        if (res == 1) printf("Max Heap\n");
        else if (res == -1) printf("Min Heap\n");
        else printf("Not Heap\n");
        post_order.clear();
        post_tranversal(1);
        for (size_t k = 0; k < post_order.size(); k++) {
            printf("%d%c", post_order[k], k == post_order.size() - 1 ? '\n' : ' ');
        }
    }
}
