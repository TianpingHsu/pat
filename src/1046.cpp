#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_EXITS = 100000 + 1;
int D[MAX_EXITS], sums[MAX_EXITS]={0};
int N, M;

int main()
{
    memset(D, -1, sizeof(int) * MAX_EXITS);
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &D[i]);
        sums[i] = D[i];
        sums[i] += sums[i - 1];
    }
    int total = sums[N];
    scanf("%d", &M);
    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == y) {
            printf("0\n");
            continue;
        }
        if (x > y) std::swap(x, y);
        // x < y
        int z = sums[y - 1] - sums[x - 1];
        z = z < total - z ? z : total - z;
        printf("%d\n", z);
    }
}
