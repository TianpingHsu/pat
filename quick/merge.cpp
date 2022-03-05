#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_SIZE = 101;
int initial_seq[MAX_SIZE], N, current_seq[MAX_SIZE], tmp[MAX_SIZE];

bool match_seq(const int *a, const int *b, int n) {
        for (int i = 1; i <= n; i++) {
                if (a[i] != b[i]) return false;
        }
        return true;
}

bool insertion_sort(int* seq, int n) {
        bool is_match = false;
        for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j > 1; j--) {
                        if (seq[j] < seq[j - 1]) std::swap(seq[j], seq[j - 1]);
                }
                if (is_match) {
                        for (int k = 1; k <= n; k++) {
                                current_seq[k] = seq[k];
                        }
                        return true;
                }
                is_match = match_seq(seq, current_seq, n);
        }
        return false;
}

void merge(int *a, int l1, int r1, int l2, int r2) {
    std::vector<int> v;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
        if (a[i] <= a[j]) {
            v.push_back(a[i++]);
        } else {
            v.push_back(a[j++]);
        }
    }
    while (i <= r1) v.push_back(a[i++]);
    while (j <= r2) v.push_back(a[j++]);
    //printf("%d : %d -- %d : %d ::=> ",l1, r1, l2, r2);
    for (size_t k = 0; k < v.size(); k++) {
        //printf("%d ", v[k]);
        a[k + l1] = v[k];
    }
    //printf("\n");
}

void merge_sort_iter(int *seq, int n) {
    bool is_match = false;
    for (int step = 2; step / 2 <= n; step *= 2) {
        for (int i = 1; i <= n; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= n) {
                merge(seq, i, mid, mid + 1, std::min(n, i + step - 1));
            }
        }
                if (is_match) {
                        for (int k = 1; k <= n; k++) {
                                current_seq[k] = seq[k];
                        }
            break;
                }
                is_match = match_seq(seq, current_seq, n);
    }
}

int main() {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                scanf("%d", &initial_seq[i]);
                tmp[i] = initial_seq[i];
        }
        for (int i = 1; i <= N; i++) {
                scanf("%d", &current_seq[i]);
        }
        if (insertion_sort(initial_seq, N)) {
                printf("Insertion Sort\n");
        }
        else {
                merge_sort_iter(tmp, N);
                printf("Merge Sort\n");
        }
        for (int i = 1; i <= N; i++) {
                printf("%d%c", current_seq[i], i == N ? '\n' : ' ');
        }
        return 0;
}
