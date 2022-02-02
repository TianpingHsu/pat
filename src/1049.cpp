#include <cstdio>
#include <map>
using namespace std;

map<int, int> m = {{0, 0}};

int f(int x) {
    if (m.find(x) != m.end()) return m[x];

    int y = x;
    int base = 1;
    int k = 0;
    while (y /= 10) {
        base *= 10;
        k = y % 10;
    };
    y = x - k * base;
    int count = 0;
    int i = 1;
    for (; i < k; i++) {
        if (i == 1) count += base;
        count += f(base - 1);
    }
    if (i == 1) count += y + 1;
    if (i == k) count += f(y);
    count += f(base - 1);
    return m[x] = count;
}

int main()
{
    for (int i = 1; i < 10; i++) m[i] = 1;
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
}
