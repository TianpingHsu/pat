#include <cstdio>
#include <string>
#include <map>
using namespace std;

static map<int, char> m;

char to_char(int x) {
    static int flag = false;
    if (!flag) {
        m = {
            { 10, 'A' },
            { 11, 'B' },
            { 12, 'C' }
        };
        for (int i = 0; i < 10; i++) {
            m.insert({i, i + '0'});
        }
        flag = true;
    }
    return m[x];
}

string to_Mars(int color) {
    string s;
    int b = color % 13;
    color /= 13;
    int a = color % 13;
    s.push_back(to_char(a));
    s.push_back(to_char(b));
    return s;
}

int main()
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    string result;
    result += to_Mars(r);
    result += to_Mars(g);
    result += to_Mars(b);
    printf("#%s\n", result.c_str());
}
