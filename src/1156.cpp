#include <cstdio>
#include <cmath>
int N;
bool is_prime(int x) {
    if (x <= 1) return false;
    int sqr = sqrt(x);
    for (int i = 2; i <= sqr; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &N);
    if (is_prime(N)) {
        if (is_prime(N - 6)) {
            printf("Yes\n%d\n", N-6);
            return 0;
        } else if (is_prime(N + 6)) {
            printf("Yes\n%d\n", N+6);
            return 0;
        } 
    } 
    printf("No\n");
    for (int i = N + 1;; i++) {
        if (is_prime(i) && (is_prime(i - 6) || is_prime(i + 6))) {
            printf("%d\n", i);
            break;
        }
    }
}
