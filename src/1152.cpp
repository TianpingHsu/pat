#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int L, K;

bool is_prime(unsigned long long x) {
    if (x <= 1) return false;
    long long sqr = std::sqrt(x);
    for (int i = 2; i <= sqr; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &L, &K);
    string s;
    cin >> s;
    if (K <= L) {
        for (int i = 0; i <= (int)s.size() - K; i++) {
            //if ((s[i + K - 1] - '0') % 2 == 0) continue;
            if (is_prime(stoi(s.substr(i, K)))) {
                cout << s.substr(i, K);
                return 0;
            }
        } 
    }
    printf("404\n");
}
