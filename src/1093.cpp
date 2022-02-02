#include <cstdio>
#include <cstring>

static const int MAX_LIMIX = 100000 + 1;
char s[MAX_LIMIX] = {0};
int d[MAX_LIMIX] = {0};
int result = 0;
int len = 0;
int last_t = -1;
int first_p = MAX_LIMIX;
bool exist_a = false;

bool init() {
    scanf("%s", s);
    len = strlen(s);
    int count_t = 0;
    for (auto i = len - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            count_t ++;
            d[i] = count_t;
            if (last_t == -1) last_t = i;
        }
        if (s[i] == 'P') {
            if (first_p > i) first_p = i;
        }
        if (s[i] == 'A') exist_a = true;
    }
    if (!exist_a || (last_t - first_p <= 1)) return false;
    return true;
}

int main() {
    if (!init()) {
        result = 0;
    } else {
        for (auto k = last_t - 1; k >= first_p; k--) {
            if (s[k] == 'A') {
                for (int i = k + 1; i <= last_t; i++) {
                    if (s[i] == 'T') {
                        d[k] = d[i];
                        break;
                    }
                }
            } else if (s[k] == 'P') {
                for (int i = k + 1; i < last_t; i++) {
                    if (s[i] == 'P') {
                        d[k] = d[k] + d[i];
                        break;
                    }
                    if (s[i] == 'A') {
                        d[k] = d[k] + d[i];
                    }
                }
            }
        }
        for (auto k = first_p; k < last_t; k++) {
            if (s[k] == 'P') {
                result += result + d[k];
                if (result > 1000000007) result %= 1000000007;
            }
        }
    }
    printf("%d", result);
    return 0;
}
