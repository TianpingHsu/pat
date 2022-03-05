#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1024;

void print_arr(const int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// a >= b
int gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a < b) std::swap(a, b);
    return a / gcd(a, b) * b;
}

bool is_prime(int x) {
    if (x == 1) return false;
    int y = sqrt(x);
    for (int i = 2; i <= y; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void filter_primes() {
    static int arr[MAX_SIZE], is_prime[MAX_SIZE];
    static int len = 0;
    if (!len) memset(is_prime, 1, sizeof(int) * MAX_SIZE);
    for (int i = 2; i < MAX_SIZE; i++) {
        if (is_prime[i]) {
            arr[len++] = i;
            for (int j = i; j < MAX_SIZE; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

void split_num(int n) {
    int d[64], count = 0;
    do {
        d[count++] = n % 10;
    } while (n /= 10);
    std::reverse(d, d + count);
}

long long to_num(int *d, int count) {
    long long sum = 0;
    for (int i = 0; i < count; i++) {
        sum *= 10;
        sum += d[i];
    }
    return sum;
}

struct Fraction {
    long long up, down;
};

Fraction reduction(Fraction x) {
    if (x.down < 0) {
        x.down = -x.down;
        x.up = - x.up;
    }
    if (x.up == 0) {
        x.down = 1;
    } else {
        int d = gcd(std::abs(x.up), std::abs(x.down));
        x.up /= d;
        x.down /= d;
    }
    return x;
}

Fraction add(Fraction a, Fraction b) {
    Fraction c;
    c.up = a.up * b.down + a.down * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

Fraction sub(Fraction a, Fraction b) {
    Fraction c;
    c.up = a.up * b.down - a.down * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction c;
    c.up = a.up * b.up;
    c.down = a.down * b.down;
    return reduction(c);
}

Fraction divide(Fraction a, Fraction b) {
    Fraction c;
    c.up = a.up * b.down;
    c.down = a.down * b.up;
    return reduction(c);
}

int partition(int* a, int l, int r) {
    int pivot = a[l], i = l, j = l + 1;
    while (j <= r) {
        if (a[j] <= pivot) std::swap(a[++i], a[j]);
        j++;
    }
    std::swap(a[l], a[i]);
    return i;
}

int partition_v2(int *a, int l, int r) {
    int pivot = a[l], i = l, j = r;
    while (i < j) {
        while (i < j && a[j] > pivot) j--;
        while (i < j && a[i] <= pivot) i++;
        std::swap(a[i], a[j]);
    }
    std::swap(a[l], a[i]);
    return i;
}

// a should be ordered, assert(l <= r)
int bs(int *a, int l, int r, int x) {
    while (l <= r) {
        int m = l + r/2;
        if (x == a[m]) return m;
        else if (x > a[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

struct BigN {
    const static int MAX_LEN = 1024;
    int d[MAX_LEN] = {0}, len = 0;
};

bool bn_less(const BigN &a, const BigN &b) {
    if (a.len == b.len) {
        for (int i = 0; i < a.len; i++) {
            if (a.d[i] < b.d[i]) return true;
        }
        return false;
    }
    return a.len < b.len;
}
bool bn_equal(const BigN &a, const BigN &b) {
    if (a.len == b.len) {
        for (int i = 0; i < a.len; i++) {
            if (a.d[i] != b.d[i]) return false;
        }
        return true;
    }
    return false;
}

BigN bn_add(BigN &a, BigN &b) {
    BigN c;
    int carry = 0;
    int len = max(a.len, b.len);
    for (int i = 0; i < len; i++) {
        c.d[c.len++] = (a.d[i] + b.d[i] + carry) % 10;
        carry = (a.d[i] + b.d[i] + carry) / 10;
    }
    return c;
}

// assert b <= a
BigN bn_sub(BigN &a, BigN &b) {
    BigN c;
    int len = max(a.len, b.len);
    for (int i = 0; i < len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len && !c.d[c.len]) c.len--;
    if (!c.len) c.len = 1;
    return c;
}

BigN bn_mul(BigN &a, const int b) {
    BigN c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int tmp = b * a.d[i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

BigN bn_div(BigN &a, const int b, int &r) {
    BigN c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b) {
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len && !c.d[c.len]) c.len--;
    if (!c.len) c.len = 1;
    return c;
}
