#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1001;
int dp[MAX_SIZE][MAX_SIZE];
char is_symetric[MAX_SIZE][MAX_SIZE];
char s[MAX_SIZE];
int len = -1;

bool is_symetric_str(int i, int j) {
    if (i < j) {
        if (is_symetric[i][j] != 0) return is_symetric[i][j] == '1';
        do {
            if (s[i] != s[j]) return (is_symetric[i][j] = '0') == '1';
        } while (++i < --j);
    }
    return (is_symetric[i][j] = '1') == '1';
}

int solu(int i, int j)
{
    if (i <= j) {
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) {
            if (is_symetric_str(i + 1, j - 1)) {
                is_symetric[i][j] = '1';
                return dp[i][j] = j - i + 1;
            } 
            is_symetric[i][j] = '0';
        } 
        return dp[i][j] = max(solu(i + 1, j), solu(i, j - 1));
    }    
    return dp[i][j] = 0;
}

int main()
{
    memset(dp, -1, sizeof(int) * MAX_SIZE * MAX_SIZE);
    memset(is_symetric, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);
    fgets(s, sizeof(s), stdin);
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    printf("%d\n", solu(0, len - 1));
}
