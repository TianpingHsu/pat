
#include <cstdio>
#include <list>
#include <vector>
using namespace std;

struct Node {
    long long exp;
    double coef;
};

list<Node> result;
list<Node> A, B;

void read_list(int n, list<Node> &l) {
    for (int i = 0; i < n; i++) {
        long long exp;
        double coef;
        scanf("%lld %lf", &exp, &coef);
        l.push_back({exp, coef});
    }
}

list<Node> add_two_lists(const list<Node> &a, const list<Node> &b) {
    if (!a.size()) return b;
    if (!b.size()) return a;
    list<Node> l;
    auto ita = a.begin(), itb = b.begin();
    while (ita != a.end() && itb != b.end()) {
        if (ita->exp == itb->exp) {
            if (ita->coef + itb->coef != 0.0) {
                l.push_back({ita->exp, ita->coef + itb->coef});
            }
            ita++, itb++;
        } else  if (ita->exp > itb->exp) {
            l.push_back({ita->exp, ita->coef});
            ita++;
        } else {
            l.push_back({itb->exp, itb->coef});
            itb++;
        }
    }
    if (ita == a.end()) {
        while (itb != b.end()) l.push_back(*itb++);
    } else {
        while (ita != a.end()) l.push_back(*ita++);
    }
    return l;
}
list<Node> multiply(Node node, list<Node> &l) {
    list<Node> tmp;
    if (!l.size()) return tmp;
    for (auto item : l) {
        tmp.push_back({node.exp + item.exp, node.coef * item.coef});
    }
    return tmp;
}

void print(const list<Node> &l)
{
    printf("%lu", l.size());
    for (auto node : l) {
        printf(" %lld %.1lf", node.exp, node.coef);
    }
    printf("\n");
}
int main() {
    int a, b;
    scanf("%d", &a);
    read_list(a, A);
    scanf("%d", &b);
    read_list(b, B);
    for (auto node : A) {
        list<Node> tmp = multiply(node, B);
        //print(tmp);
        result = add_two_lists(result, tmp);
        //print(result);
    }
    print(result);
}

