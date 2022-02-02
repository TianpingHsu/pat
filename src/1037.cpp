#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

vector<long long> magic_coupons_p, magic_coupons_n,
    product, bonus;

long long solu(bool flag) {
    long long sum = 0;
    if (flag) {

        for (size_t i = 0; i < magic_coupons_p.size()
                && i < product.size(); i++) {
            sum += magic_coupons_p[i] * product[i];
        }

    } else {
        for (size_t i = 0; i < magic_coupons_n.size()
                && i < bonus.size(); i++) {
            sum += magic_coupons_n[i] * bonus[i];
        }
    }
    return sum;
}

int main()
{
    long long Nc, Np;
    scanf("%lld", &Nc);
    for (long long i = 0, x; i < Nc; i++) {
        scanf("%lld", &x);
        if (x > 0) magic_coupons_p.push_back(x);
        if (x < 0) magic_coupons_n.push_back(x);
    }
    scanf("%lld", &Np);
    for (long long i = 0, x; i < Np; i++) {
        scanf("%lld", &x);
        if (x > 0) product.push_back(x);
        else  bonus.push_back(x);
    }
    sort(magic_coupons_p.begin(), magic_coupons_p.end(), greater<long long>());
    sort(product.begin(), product.end(), greater<long long>());
    sort(magic_coupons_n.begin(), magic_coupons_n.end());
    sort(bonus.begin(), bonus.end());
    printf("%lld", solu(true) + solu(false));
}
