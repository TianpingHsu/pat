#include <set>
#include <vector>
#include <cstdio>
using namespace std;
int N, K;
vector<set<int>> vs = {set<int>()};

double process_one_case(int x, int y) {
    set<int> &sx = vs[x], &sy = vs[y];
    int size_x = sx.size(), size_y = sy.size();
    int sames = 0;
    for (const auto x : sx) {
        if (sy.find(x) != sy.end()) sames++;
    }
    return ((sames * 1.0) / (size_x + size_y - sames)) * 100.0;
}

int main()
{
    scanf("%d", &N);
    set<int> dummy;
    for (int i = 0; i < N; i++) {
        int M, x;
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &x);
            dummy.insert(x);
        }
        vs.push_back(dummy);
        dummy.clear();
    }
    scanf("%d", &K);
    vector<double> result;
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        result.push_back(process_one_case(x, y));
    }
    for (size_t i = 0; i < result.size(); i++) {
        printf("%.1lf%%\n", result[i]);
    }
}

