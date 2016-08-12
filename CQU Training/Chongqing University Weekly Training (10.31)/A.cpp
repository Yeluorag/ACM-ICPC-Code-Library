#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char str[N], key[55];
int head, tail;
struct node {
    int count;
    struct node *next[26];
    struct node *fail;
    void init() {
        for(int i = 0; i < 26; i ++) next[i] = NULL;
        count = 0;
        fail = NULL;
    }
} *root, *q[N];

// 建立Trie
void insert(char *str) {
    int temp, len;
    node *p = root;
    len = strlen(str);
    for(int i = 0; i < len; i ++) {
        temp = str[i] - 'a';
        if(p->next[temp] == NULL)
            p->next[temp] = new node();
        p = p->next[temp];
    }
    p->count ++;
}

void build_ac() {
    q[tail ++] = root;
    while(head != tail) {
        node *p = q[head ++];
        node *temp = NULL;
        for(int i = 0; i < 26; i ++) {
            if(p->next[i] != NULL) {
                if(p == root) p->next[i]->fail = root;
                else {
                    temp = p->fail;
                    while(temp != NULL) {
                        if(temp ->next[i] != NULL) {
                            p->next[i]->fail = temp->next[i];
                            break;
                        }
                        temp = temp->fail;
                    }
                    if(temp == NULL) p->next[i]->fail = root;
                }
                q[tail ++] = p->next[i];
            }
        }
    }
}

int query() {
    int index, len, result;
    node *p = root;
    result = 0;
    len = strlen(str);
    for(int i = 0; i < len; i ++) {
        index = str[i] - 'a';
        while(p->next[index] == NULL && p != root) p = p->fail;
        p = p->next[index];
        if(p == NULL) p = root;
        node *temp = p;
        while(temp != root && temp->count != -1) {
            result += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
    }
    return result;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
 //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        head = tail = 0;
        root = new node();
        si(n);
        getchar();
        for(int i = 0; i < n; i ++) {
            gets(key);
            insert(key);
        }
        build_ac();
        scanf("%s", str);
        printf("%d\n", query());
    }
    
    return 0;
}