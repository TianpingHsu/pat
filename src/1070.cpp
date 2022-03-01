#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Mooncake {
    double inventory_amounts, price, single;
};
int N, D;

int main() {
    scanf("%d %d", &N, &D);
    vector<Mooncake> cakes;
    for (int i = 0; i < N; i++) {
        Mooncake cake;
        scanf("%lf", &cake.inventory_amounts);
        cakes.push_back(cake);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lf", &cakes[i].price);
        cakes[i].single = cakes[i].price / cakes[i].inventory_amounts;
    }
    sort(cakes.begin(), cakes.end(), [](const Mooncake& a, const Mooncake& b) {
            return a.single > b.single;
            });
    double sum = 0;
    double epsilon = 1e-6;
    for (int i = 0; i < N && D > epsilon; i++) {
        if (D >= cakes[i].inventory_amounts) {
            sum += cakes[i].price;
            D -= cakes[i].inventory_amounts;
        } else {
            sum += cakes[i].single * D;
            D = 0;
        }
    }
    printf("%.2lf\n", sum);
}
