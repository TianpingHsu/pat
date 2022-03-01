#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool is_legal(string s, int &x, double &y) {
    size_t i = 0;
    if (s[i] == '-') i++;
    int dot = 0;
    for (; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            continue;
        } else {
            if (dot == 0 && s[i] == '.') {
                dot++;
                if (i == 0) return false;
                if (s[i - 1] > '9' || s[i - 1] < '0') return false;
                if (s.size() - i - 1 > 2) return false;
                continue;
            }
            return false;
        }
    }
    if (!dot) {
        if (s.size() > 5) return false;
        x = stoi(s);
        return x >= -1000 && x <= 1000;
    } else {
        y = stof(s);
        return y >= -1000 && y <= 1000;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    double total = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        double y = 10000;
        int x = 10000;
        if (is_legal(in, x, y)) {
            count++;
            if (x!=10000) total += x;
            else total += y;
        } else {
            cout << "ERROR: " << in << " " << "is not a legal number" << endl;
        }
    }
    if (!count) {
        printf("The average of 0 numbers is Undefined\n");
    } else {
        double result = total / count;
        printf("The average of %d number%sis %.2lf\n", count, count == 1 ? " " : "s ", result);
    }
}
