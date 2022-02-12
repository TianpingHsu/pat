#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

bool is_prime(int n) {
    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

const char* awards[] = {
    "Mystery Award",
    "Minion", 
    "Chocolate"
};

int process_award(int rank) {
    if (rank == 1) return 0;
    if (is_prime(rank)) return 1;
    return 2;
}

struct Result {
    bool checked = false;   
    int award = -1;  // 0, 1, 2
};

int main() {
    int N, K;
    scanf("%d", &N);
    map<int, Result> m;
    for (int i = 1, id; i <= N; i++) {
        scanf("%d", &id);
        Result r;
        r.award = process_award(i);
        m[id] = r;
    }
    scanf("%d", &K);
    for (int i = 0, id; i < K; i++) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (m.find(id) != m.end()) {
            if (m[id].checked) {
                printf("Checked\n");
            } else {
                printf("%s\n", awards[m[id].award]);
                m[id].checked = true;
            }
        } else {
            printf("Are you kidding?\n");
        }
    }
}
