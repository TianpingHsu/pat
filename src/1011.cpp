#include <utility>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<double, char>> v;
    for (int i = 0; i < 3; i++) {
        double w, t, l;
        char c;
        scanf("%lf %lf %lf", &w, &t, &l);
        double _max = max({w, t, l});
        if (_max == w) c = 'W';
        if (_max == t) c = 'T';
        if (_max == l) c = 'L';
        v.push_back({_max, c});
    }
    double s = 1.0;
    for (auto p : v) {
        s *= p.first;
    }
    s = (s * 0.65 - 1) * 2;
    for (auto p : v) {
        printf("%c ", p.second);
    }
    printf("%.2lf\n", s);
}
