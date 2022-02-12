#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100001;
long long numbers[MAX_SIZE];

int main() {
    memset(numbers, 0, sizeof(double) * MAX_SIZE);
    int N;
    long long sum = 0.0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        double tmp;
        scanf("%lf", &tmp);
        numbers[i] = tmp * 1000.0;
        sum += numbers[i] * (i + 1) * (N - i);
    }
    printf("%.2lf", sum/1000.0);
}
