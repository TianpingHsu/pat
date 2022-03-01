#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
map<int, set<int>> groups;
const int MAX_SIZE = 210;
int N, M, K, L;
set<int> heads[MAX_SIZE];

int main(){
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        heads[i].insert(i);
    }
    for (int i = 1, x, y; i <= M; i++) {
        scanf("%d %d", &x, &y);
        heads[x].insert(y);
        heads[y].insert(x);
    }
    scanf("%d", &K);
    for (int i = 1; i <= K; i++){
        scanf("%d", &L);
        set<int> current_v;
        for (int j = 0, z; j < L; j++) {
            scanf("%d", &z);
            current_v.insert(z);
        }

        bool flag = true;
        for (auto x : current_v) {
            for (auto y : current_v) {
                if (heads[x].find(y) == heads[x].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) break;
        }
        if (flag == false) {
            printf("Area %d needs help.\n", i);
        } else {
            bool all_friends = true;
            bool continue_current = false;
            for (int k = 1; k <= N; k++) {
                continue_current = false;
                all_friends = true;
                if (current_v.find(k) == current_v.end()) {
                    for (auto x : current_v) {
                        if (heads[x].find(k) == heads[x].end()) {
                            all_friends = false;
                            break;
                        }
                    }
                    if (all_friends) {
                        printf("Area %d may invite more people, such as %d.\n",i, k);
                        continue_current = true;
                        break;
                    }
                }
            }
            if (!continue_current) {
                printf("Area %d is OK.\n", i);
            }
        }
    }
}

