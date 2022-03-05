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

void sink(int *a, int i, int n) {
    if (i > n) return;
        int left = 2 * i, right = 2 * i + 1, candidate = left;
        if (left <= n && right <= n) candidate = a[left] > a[right] ? left : right;
        if (candidate <= n && a[i] < a[candidate]) {
                std::swap(a[i], a[candidate]);
                sink(a, candidate, n);
        }
}
void print_a(int *a) {
        for (int i = 1; i <= N; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}
void heapify(int *a, int n) {
        for (int i = n / 2; i >= 1; i--) {
                sink(a, i, n);
        }
}

bool heap_sort(int *seq, int n) {
        heapify(seq, n);
        bool is_match = false;
    while (true) {
                std::swap(seq[1], seq[n]);
                n--;
                sink(seq, 1, n);

                if (is_match) {
                        for (int k = 1; k <= N; k++) {
                                current_seq[k] = seq[k];
                        }
                        return true;
                }
                is_match = match_seq(seq, current_seq, N);
        }
        return false;
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
                heap_sort(tmp, N);
                printf("Heap Sort\n");
        }
        for (int i = 1; i <= N; i++) {
                printf("%d%c", current_seq[i], i == N ? '\n' : ' ');
        }
        return 0;
}

