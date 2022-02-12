#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v = {0};
set<int> s;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        if (x <= 0) continue;
        if (s.find(x) != s.end()) continue;
        s.insert(x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int i = 1;
    for (; i < v.size(); i++) {
        if (v[i] != i) {
            printf("%d\n", i);
            return 0;
        }
    }
    if (i == v.size()) {
        printf("%d\n", i);
    }
}
