#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> couples;
set<int> guests;

int main() {
    int N, M;
    scanf("%d", &N);
    for (int i = 0, x, y; i < N; i++) {
        scanf("%d %d", &x, &y);
        couples[x] = y, couples[y] = x;
    }
    scanf("%d", &M);
    for (int i = 0, guest; i < M; i++) {
        scanf("%d", &guest);
        guests.insert(guest);
    }
    vector<int> result;
    for (auto guest : guests) {
        if (couples.find(guest) == couples.end()) {
            result.push_back(guest);
        } else if (guests.find(couples[guest]) == guests.end()) {
            result.push_back(guest);
        } else {
            continue;
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", (int)result.size());
    for (size_t i = 0; i < result.size(); i++) {
        printf("%05d%c", result[i], result.size() - 1 == i ? '\n' : ' ');
    }
}
