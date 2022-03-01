#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int N,m,n;
vector<int> v;
int matrix[101][101];

int x = 1, y = 1;
bool right() {
    if (y < n && matrix[x][y + 1] == 0) {
        y++;
        return true;
    }
    return false;
}
bool down() {
    if (x < m && matrix[x + 1][y] == 0) {
        x++;
        return true;
    }
    return false;
}
bool left() {
    if (y > 1 && matrix[x][y - 1] == 0) {
        y--;
        return true;
    }
    return false;
}
bool up() {
    if (x > 1 && matrix[x - 1][y] == 0) {
        x--;
        return true;
    }
    return false;
}

enum class DIRECTION {
    RIGHT, DOWN, LEFT, UP
};

int main() {
    memset(matrix[0], 0, sizeof(int) * 101 * 101);
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    m = std::sqrt(N);
    while (N % m != 0) {m++;};
    n = N / m;
    if (m < n) std::swap(m, n);
    //printf("\n(m, n): (%d, %d)\n", m, n);
    DIRECTION d = DIRECTION::UP;
    for (size_t i = 0; i < v.size(); i++) {
        //printf("%d%c", v[i], i == v.size() - 1 ? '\n' : ' ');
        matrix[x][y] = v[i];
        if (d == DIRECTION::UP) {
            if (up()) continue;
            d = DIRECTION::RIGHT;
            if (right()) {
                continue;
            }
        }
        if (d == DIRECTION::RIGHT) {
            if (right()) continue;
            d = DIRECTION::DOWN;
            if (down()) {
                continue;
            }
        }
        if (d == DIRECTION::DOWN) {
            if (down()) continue;
            d = DIRECTION::LEFT;
            if (left()) {
                continue;
            }
        }
        if (d == DIRECTION::LEFT) {
            if (left()) continue;
            d = DIRECTION::UP;
            if (up()) {
                continue;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d%c", matrix[i][j], j == n ? '\n' :' ');
        }
    }
}
