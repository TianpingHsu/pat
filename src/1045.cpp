#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, L;
vector<int> order;
vector<int> stripe;
map<int, bool> m_tb;
static int dp[201][10001] = {0};
int result = 0;

int solu(int m, int l) {
    if (m < 0 || l < 0) return 0;
    if (dp[m][l] != -1) return dp[m][l];

    if (order[m] == stripe[l]) {
        //return dp[m][l] = 1 + dp[m][l - 1];
        return dp[m][l] = 1 + solu(m, l - 1);
    } else {
        //return dp[m][l] = max(dp[m][l - 1], dp[m - 1][l]);
        return dp[m][l] = max(solu(m, l - 1), solu(m - 1, l));
    }
}

void print_it(const vector<int> &v) {
    for (auto x : v) printf("%d ", x);
    printf("\n");
}

int main()
{
    memset(dp, -1, sizeof(int) * 201 * 10001);
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        order.push_back(x);
        if (m_tb.find(x) == m_tb.end()) {
            m_tb.insert({x, true});
        }
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int x;
        scanf("%d", &x);
        if (m_tb.find(x) != m_tb.end()) {
            stripe.push_back(x);
        }
    }
    L = stripe.size();
    //print_it(order);
    //print_it(stripe);
    if (L == 0) {
        printf("0\n");
        return 0;
    }
    int count = 0;
    for (int i = 0; i < L; i++) {
        dp[0][i] = 0;
        if (stripe[i] == order[0]) {
            count++;
        }
        dp[0][i] = count;
    }
    count = 0;
    for (int i = 0; i < M; i++) {
        dp[i][0] = 0;
        if (stripe[0] == order[i]) {
            count ++;
        }
        dp[i][0] = count;
    }
    /*
    printf("\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < L; j++) {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    result = solu(M - 1, L - 1);
    printf("%d\n", result);
}
