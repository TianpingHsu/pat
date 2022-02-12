#include <cstdio>
#include <algorithm>
#include <functional>

const int MAX_N = 1e5 + 1;
int miles[MAX_N] = {0}, N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &miles[i]);
    }
    std::sort(miles, miles + N, std::greater<int>());
    int i = 0;
    for (; i < N; i++) {
        if (miles[i] > i + 1) {
            continue;
        } else {
            break;
        }
    }
    printf("%d\n", i);
}
