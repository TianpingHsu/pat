#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

struct Info {
    char name[16] = {0}, gender, id[16] = {0};
    int grade;
};

vector<Info> females, males;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        Info info;
        scanf(" %s %c %s %d", info.name, &info.gender, info.id, &info.grade);
        if (info.gender == 'F') {
            females.push_back(info);
        } else {
            males.push_back(info);
        }
    }
    sort(females.begin(), females.end(), [](const Info& a, const Info &b) {
            return a.grade > b.grade;
            });
    sort(males.begin(), males.end(), [](const Info& a, const Info &b){
        return a.grade < b.grade;
    });
    if (females.size()) {
        printf("%s %s\n", females[0].name, females[0].id);
    } else {
        printf("Absent\n");
    }

    if (males.size()) {
        printf("%s %s\n", males[0].name, males[0].id);
    } else {
        printf("Absent\n");
    }
    
    if (!males.size() || !females.size()) {
        printf("NA\n");
    } else {
        printf("%d\n", females[0].grade - males[0].grade);
    }
}
