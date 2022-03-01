#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Info {
    int rank;
    string school;
    map<string, int> testees;
    int tws;
    int n;
};

map<string, int> schools;
vector<Info> result;

int main() {
    int N;
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        char id[16] = {0}, school[16] = {0};
        int score;
        scanf(" %s %d %s", id, &score, school);
        char *p = school;
        while (*p) {  // to lower case
            if (*p >= 'A' && *p <= 'Z') *p = *p - 'A' + 'a';
            p++;
        }
        if (schools.find(school) != schools.end()) {
            result[schools[school]].testees[id] = score;
        } else {
            schools[school] = result.size();
            Info t;
            t.school = school;
            t.testees[id] = score;
            result.push_back(t);
        }
    }
    for (size_t i = 0; i < result.size(); i++) {
        double weight = 0;
        for (auto it = result[i].testees.begin(); it != result[i].testees.end(); it++) {
            if (it->first[0] == 'A') {
                weight += it->second;
            } else if (it->first[0] == 'B') {
                weight += it->second/1.5;
            } else {
                weight += it->second * 1.5;
            }
        }
        result[i].tws = weight;
        result[i].n = result[i].testees.size();
    }
    sort(result.begin(), result.end(), [](const Info&a, const Info&b) {
            if (a.tws == b.tws) {
                if (a.n == b.n) {
                    return a.school < b.school;
                }
                return a.n < b.n;
            }
            return a.tws > b.tws;
            });
    int tws = -1, rank = 1;
    for (size_t i = 0; i < result.size(); i++) {
        if (tws != result[i].tws) {
            result[i].rank = i + 1;
            rank = i + 1;
            tws = result[i].tws;
        } else {
            result[i].rank = rank;
        }
    }
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i].rank << " " << result[i].school << " " << result[i].tws << " " << result[i].testees.size() << endl;
    }
}
