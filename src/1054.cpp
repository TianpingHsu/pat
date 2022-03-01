#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int M, N, total;

map<string, int> colors;

int main() {
    scanf("%d %d", &M, &N);
    total = M * N;
    string result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string color;
            cin >> color;
            if (colors.find(color) == colors.end()) {
                colors[color] = 1;
            } else {
                colors[color]++;
            }
            if (colors[color] > total/2) {
                result = color;
            }
        }
    }
    cout << result << endl;
}
