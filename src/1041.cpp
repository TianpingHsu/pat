
#include <cstdio>
#include <vector>
using namespace std;

int h[10000 + 1] = {0};
vector<int> v;

int main()
{
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        h[x] ++;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (h[v[i]] == 1) {
            printf("%d\n", v[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
