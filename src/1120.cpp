#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<int> results;

int calc_digits(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x/=10;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        results.insert(calc_digits(x));
    }
    vector<int> t(results.begin(), results.end());
    printf("%lu\n", results.size());
    for (size_t i = 0; i < t.size(); i++) {
        printf("%d%c", t[i], i == t.size() - 1 ? '\n' : ' ');
    }
}
