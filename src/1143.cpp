#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int M, N;
struct Node {
    int k;
    Node *l = NULL, *r = NULL;
};
const int MAX_SIZE = 10100;
int preorder[MAX_SIZE];
Node*Preorder(int h,int t)
{
    if(h>t)
        return nullptr;
    Node *p = new Node;
    p->k = preorder[h];
    int i;
    for(i=h+1;i<=t;i++)
        if(preorder[i]>preorder[h])
            break;
    p->l = Preorder(h+1,i-1);
    p->r = Preorder(i,t);
    return p;
}

int main() {
    scanf("%d %d", &M, &N);
    std::set<int> s;
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
        s.insert(preorder[i]);
    }
    Node* root = Preorder(0, N - 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        scanf("%d %d", &U, &V);
        auto it_u = s.find(U);
        auto it_v = s.find(V);
        if (it_u == s.end() && it_v == s.end()) {
            printf("ERROR: %d and %d are not found.\n",U,V);
        } else if (it_v == s.end()) {
            printf("ERROR: %d is not found.\n", V);
        } else if (it_u == s.end()) {
            printf("ERROR: %d is not found.\n",U);
        } else {
            int a = U, b = V;
            Node *current = root;
            while((a>current->k && b>current->k) || (a<current->k && b<current->k))
            {
                if(a>current->k && b>current->k)
                    current = current->r;
                else
                    current = current->l;
            }
            if((a>current->k && b<current->k) || (a<current->k && b>current->k))
                printf("LCA of %d and %d is %d.\n",a,b,current->k);
            else if(a == current->k)
                printf("%d is an ancestor of %d.\n",a,b);
            else
                printf("%d is an ancestor of %d.\n",b,a);
        }
    }
}

