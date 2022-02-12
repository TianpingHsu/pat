#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 32;

string double_it(string a) {
    string res;
    int carry_bit = 0;
    reverse(a.begin(), a.end());
    for (size_t i = 0; i < a.size(); i++) {
        int current = (a[i] - '0') * 2 + carry_bit;
        carry_bit = current / 10;
        current %= 10;
        res.push_back(current + '0');
    }
    if (carry_bit) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a;
    cin >> a;
    string b = double_it(a);
    string c = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    cout << c << endl;;
}
