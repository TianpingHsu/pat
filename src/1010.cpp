#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

char N1[16] = {0}, N2[16] = {0};
map<char, int> m;

long long calc_num(const char* s, int radix) {
    long long sum = 0;
    while (*s) {
        sum *= radix;
        sum += m[*s++];
    }
    return sum;
}

int main() {
    // init map
    for (int i = 0; i <= 9; i++) {
        m[i + '0'] = i;
    }
    for (int i = 0; i < 26; i++) {
        m[i + 'a'] = i + 10;
    }
    for (auto it : m) {
        printf("%d ", it.second);
    }

    int tag, radix;
    scanf("%s %s %d %d", N1, N2, &tag, &radix);
    char *p = NULL, *q = NULL;
    if (tag == 1) {
        p = N1, q = N2;
    } else {
        p = N2, q = N1;
    }
    long long n1 = calc_num(p, radix);
    char *r = q;
    int max_num = 0;
    while (*r) {
        if (max_num < m[*r]) max_num = m[*r];
        r++;
    }
    long long low = ++max_num, high = max(n1, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long n2 = calc_num(q, mid);
        if (n2 == n1) {
            printf("%lld\n", mid);
            return 0;
        } else if (n2 > n1 || n2 < 0) {  // 'n2 < 0' means 'long long' is not big enough
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Impossible\n");
}
