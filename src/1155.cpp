#include <cstdio>
#include <vector>
using namespace std;
const int MAX_SIZE = 1024;
int heap[MAX_SIZE], N;

inline bool is_leaf(int i) { return 2 * i > N; }
bool is_max_heap(int i) {
    if (is_leaf(i)) return true;
    int left = 2 * i, right = 2 * i + 1;
    if (left <= N && right <= N) {
        if (heap[i] >= heap[left] && heap[i] >= heap[right]) return is_max_heap(left) && is_max_heap(right);
        return false;
    }
    if (left <= N && heap[i] >= heap[left]) return is_max_heap(left);
    return false;
}

bool is_min_heap(int i) {
    if (is_leaf(i)) return true;
    int left = 2 * i, right = 2 * i + 1;
    if (left <= N && right <= N) {
        if (heap[i] <= heap[left] && heap[i] <= heap[right]) return is_min_heap(left) && is_min_heap(right);
        return false;
    }
    if (left <= N && heap[i] <= heap[left]) return is_min_heap(left);
    return false;
}

void print_path(const vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        printf("%d%c", heap[v[i]], i == v.size() - 1? '\n' : ' ');
    }
}

void dfs(int i, vector<int> path) {
    path.push_back(i);
    if (is_leaf(i)) {
        print_path(path);
    } else {
        int child = 2 * i + 1;  // right
        if (child <= N) {
            dfs(child, path);
        } 
        if (child - 1 <= N) {
            dfs(child - 1, path);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &heap[i]);
    }
    vector<int> tmp;
    dfs(1, tmp);

    int structure = 0;
    if (is_max_heap(1)) structure = 1;
    else if (is_min_heap(1)) structure = -1;
    else structure = 0;
    printf("%s\n", structure == 1 ? "Max Heap" : (structure == -1 ? "Min Heap" : "Not Heap"));
}
