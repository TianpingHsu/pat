#include <cstdio>
using namespace std;

class UF {
    public:
        UF(int n);
        void union_ij(int i, int j);
        int find(int x);
        bool connected(int i, int j) {return p[i] == p[j];}
        int connected_component_count() {return count;}
    private:
        int *p = NULL;
        int size = 0;
        int count;
};

UF::UF(int n) {
    size = n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    count = n;
}

void UF::union_ij(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i == root_j) return;
    p[root_i] = root_j;
    count--;
}

int UF::find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
