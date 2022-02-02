#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> coins;
vector<bool> tb;

bool find_it(int l, int r, int v2, int idx) {
    while (l < r) {
        int m = (l + r) / 2;
        if (m == idx) {
            return find_it(l, m - 1, v2, idx) ||
                find_it(m + 1, r, v2, idx);
        }
        if (v2 == coins[m]) {
            return true;
        } else if (v2 < coins[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        coins.push_back(x);
        tb.push_back(false);
    }
    sort(coins.begin(), coins.end());
    int v1, v2;
    bool flag = false;
    for (size_t i = 0; i < coins.size(); i++) {
        tb[i] = true;
        v1 = coins[i];
        v2 = M - v1;
        if (v2 > 0 && find_it(0, coins.size(), v2, i)) {
            flag = true;
            break;
        }
        tb[i] = false;
    }
    if (!flag) {
        printf("No Solution\n");
    } else {
        printf("%d %d\n", v1, v2);
    }
}
