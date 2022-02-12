#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_N = 100008;
struct Node {
    int addr, data = 0, next = -1;
};
Node nodes[MAX_N];

void print_list(int head) {
    printf("%05d %d ", head, nodes[head].data);
    if (nodes[head].next == -1) {
        printf("-1\n");
        return;
    } else {
        printf("%05d\n", nodes[head].next);
    }
    print_list(nodes[head].next);
}

int main() {
    int head, N, K;
    scanf("%d %d %d", &head, &N, &K);
    for (int i = 0, addr, data, next; i < N; i++) {
        scanf("%d %d %d", &addr, &data, &next);
        nodes[addr].addr = addr;
        nodes[addr].data = data;
        nodes[addr].next = next;
    }
    vector<Node*> l;
    int p = head;
    while (p != -1) {
        l.push_back(&nodes[p]);
        p = nodes[p].next;
    }
    int times = l.size() / K;
    for (int i = 0; i < times; i++) {
        int start = K * i;
        reverse(l.begin() + start, l.begin() + start + K);
    }

    unsigned int i = 0;
    for (; i < l.size() - 1; i++) {
        l[i]->next = l[i + 1]->addr;
    }
    l[i]->next = -1;
    head = l[0]->addr;
    print_list(head);
}
