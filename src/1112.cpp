#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
set<char> suspect, ok;
int main() {
    int k;
    scanf("%d", &k);
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (ok.find(s[i]) != ok.end()) {
            suspect.erase(s[i]);
            continue;
        }
        int count = 0;
        size_t j = i + 1;
        for (; j < s.size(); j++) {
            if (s[i] != s[j]) break;
            count++;
        }
        if (count && (count + 1) % k == 0) suspect.insert(s[i]);
        else ok.insert(s[i]);
        i = j - 1;
    }
    int count = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (suspect.find(s[i]) != suspect.end()) {
            printf("%c", s[i]);
            suspect.erase(s[i]);
            count ++;
        }
    }
    if (count) printf("\n");

    for (size_t i = 0; i < s.size(); i++) {
        printf("%c", s[i]);
        if (ok.find(s[i]) == ok.end()) {
            i += k - 1;
        }
    }
}
