#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    int id = -1;
    double A = -1;
    int C = -1, M = -1, E = -1;
    int rka = -1, rkc = -1, rkm = -1, rke = -1;
};

bool find_it(const vector<stu> &ss, int id, stu& s) {
    for (auto x : ss) {
        if (id == x.id) {
            s = x;
            return true;
        }
    }
    return false;
}

void rank_it(vector<stu> &ss, char c) {
    double last_score = -1;
    int last_sco = -1;
    int last_rank = 0;
    for (size_t i = 0; i < ss.size(); i++) {
        if (c == 'A') {
            if (last_score != ss[i].A) {
               last_rank = i + 1; 
               last_score = ss[i].A;
            }
            ss[i].rka = last_rank;
        }

        if (c == 'C') {
            if (last_sco != ss[i].C) {
               last_rank = i + 1; 
               last_sco = ss[i].C;
            }
            ss[i].rkc = last_rank;
        }

        if (c == 'M') {
            if (last_sco != ss[i].M) {
               last_rank = i + 1; 
               last_sco = ss[i].M;
            }
           ss[i].rkm = last_rank;
        }

        if (c == 'E') {
            if (last_sco != ss[i].E) {
               last_rank = i + 1; 
               last_sco = ss[i].E;
            } 
           ss[i].rke = last_rank;
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<stu> ss;
    for (int i = 0; i < N; i++) {
        int id, c, m, e;
        scanf("%d %d %d %d", &id, &c, &m, &e);
        stu s;
        s.id = id;
        s.C = c;
        s.M = m;
        s.E = e;
        s.A = (c + m + e) / 3.0;
        ss.push_back(s);
    }
    vector<int> queries;
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        queries.push_back(x);
    }
    // sort A
    sort(ss.begin(), ss.end(), [](const stu& x, const stu& y) {
                return x.A > y.A;
            });
    rank_it(ss, 'A');

    // sort C
    sort(ss.begin(), ss.end(), [](const stu& x, const stu& y) {
                return x.C > y.C;
            });
    rank_it(ss, 'C');

    // sort M
    sort(ss.begin(), ss.end(), [](const stu& x, const stu& y) {
                return x.M > y.M;
            });
    rank_it(ss, 'M');

    // sort E
    sort(ss.begin(), ss.end(), [](const stu& x, const stu& y) {
                return x.E > y.E;
            });
    rank_it(ss, 'E');
    for (auto id : queries) {
        stu s;
        if (find_it(ss, id, s)) {
            unsigned int _min = -1;
            int idx = 0;
            static char out[] = {'A', 'C', 'M', 'E'};
            int rk[] = {s.rka, s.rkc, s.rkm, s.rke};
            for (size_t i = 0; i < 4; i++) {
                if (_min > (unsigned int)rk[i]) {
                    idx = i;
                    _min = rk[i];
                }
            }
            printf("%d %c\n", _min, out[idx]);
        } else {
            printf("N/A\n");
        }
    }
}
