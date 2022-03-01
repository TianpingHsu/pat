#include <cstdio>
#include <algorithm>
unsigned int calc(int *p, int len) {
    unsigned int sum = 0;
    for (int i = 0; i < len; i++) {
        sum *= 10;
        sum += p[i];
    }
    return sum;
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0, count; i < N; i++) {
        unsigned int x, y;
        scanf("%u", &x);
        int digits[16] = {0};
        count = 0, y = x;
        while (x) {
            digits[count++] = x % 10;
            x /= 10;
        }
        std::reverse(digits, digits + count);
        int k = count / 2;  // [0, k), [k, count)
        unsigned l = calc(digits, k);
        unsigned r = calc(digits + k, k);
        if (l == 0 || r == 0) {
            printf("No\n");
            continue;
        }
        unsigned a = y % l;
        if (a == 0) {
            y /= l;
            unsigned b = y % r;
            if (b == 0) {
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");
    }
}
