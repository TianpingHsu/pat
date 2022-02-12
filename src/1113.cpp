#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 100000 + 1;
int numbers[MAX_N], N;

int calc(int n1, int n2) {
    int s1 = 0, s2 = 0, i = 0;
    for (; i < n1; i++) {
        s1 += numbers[i];
    }
    for (;i < N; i++) {
        s2 += numbers[i];
    }
    return s2 - s1;
}

int main()
{
    int n1, n2;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    sort(numbers, numbers + N);
    n1 = N / 2;
    n2 = N - n1;
    if (n1 == n2) {
        printf("0 ");
        printf("%d\n", calc(n1, n2));
    } else  {
        printf("1 ");
        printf("%d\n", calc(n1, n2));
    }
}
