#include <iostream>
#include <set>
#include <vector>
using namespace std;

void print_set(set<int> &s) {
    cout << s.size() << ": ";
    for (auto it : s) {cout << it << " ";};
    cout << endl;
}

int main() {
    {
        set<int> s = {1, 2, 3};
    }
    {
        vector<int> v = {1, 2, 3};
        set<int> s(v.begin(), v.end());
    }
    {
        set<int> a = {1, 2, 3};
        set<int> b(a);
        set<int> c(b.begin(), b.end());
    }
    {
        set<int> s = {1, 2, 3};
        print_set(s);
        s.erase(1);
        print_set(s);
        auto it = s.begin();
        s.erase(it);
        print_set(s);
    }
    {
        // s.find(1)
        // s.empty()
        // s.insert(1);
        // s.clear();
    }
}
