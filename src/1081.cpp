#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>

long int N, result_int;
struct fract {
    long int n, d;   
} ans, tmp;

long int gcd(int x, int y) {
    if (x < y) std::swap(x, y);
    return y == 0 ? x : gcd(y, x % y);
}

fract sum_it(fract x, fract y) {
    long int gcd_xy = gcd(x.d, y.d);
    fract t;
    t.d = (x.d / gcd_xy * y.d);
    t.n = x.n*(y.d/gcd_xy) + y.n*(x.d/gcd_xy);
    gcd_xy = gcd(t.d, t.n);
    t.d /= gcd_xy;
    t.n /= gcd_xy;
    return t;
}

int main()
{
    scanf("%ld", &N);
    ans.n = 0;
    ans.d = 1;
    for (long int i = 0; i < N; i++) {
        scanf("%ld/%ld", &tmp.n, &tmp.d);
        ans = sum_it(ans, tmp);
    }
    result_int = ans.n / ans.d;
    ans.n %= ans.d;
    if (result_int) {
        printf("%ld", result_int);
        if (ans.n) {
            printf(" %ld/%ld",ans.n, ans.d);
        }
    } else {
        if (ans.n) {
            printf("%ld/%ld",ans.n, ans.d);
        } else {
            printf("0\n");
        }
    }
}

