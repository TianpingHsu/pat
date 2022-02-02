#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int N, K;
map<string, int> name_id;
map<int, string> id_name;
map<int, vector<int>> course_namelist;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= K; i++) {
        course_namelist.insert({i, vector<int>()});
    }
    for (int i = 0; i < N; i++) {
        char name[5] = {0};
        int c;
        scanf("%s %d", name, &c);
        if (name_id.find(name) == name_id.end()) {
            name_id.insert({name, i});
            id_name.insert({i, name});
        }
        int id = name_id[name];
        for (int j = 0; j < c; j++) {
            int cid;
            scanf("%d", &cid);
            course_namelist[cid].push_back(id);
        }
    }

    for (auto it = course_namelist.begin(); 
            it != course_namelist.end(); it++) {
        int course = it->first;
        vector<int> &v = it->second;
        if (!v.size()) {
            printf("%d 0\n", course);
            continue;
        }
        vector<string> names;
        for (auto id : v) {
            names.push_back(id_name[id]);
        }
        sort(names.begin(), names.end());
        printf("%d %lu\n", course, names.size());
        for (size_t i = 0; i < names.size(); i++) {
            printf("%s\n", names[i].c_str());
        }
    }
}

