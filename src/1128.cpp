#include <cstdio>
int K, N;
int queens[1001];

bool is_solu() {
    for (int i = 2; i <= N; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (queens[i] == queens[j]) return false;
            if (queens[i] - queens[j] == i - j || 
                    queens[i] - queens[j] == j - i) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &queens[i]);
        }
        if (is_solu()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
