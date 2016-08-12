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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, M = 6e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct Trie {
	Trie *next[26];
	Trie *fail;
	int isword, kind;
};
Trie *que[M], s[M];
int dp[55][N], idx, h[105];
char str[105][105];
string path[55][N];
Trie *NewNode() {
	Trie *tmp = &s[idx];
	mem(tmp->next, NULL);
	tmp->isword = 0;
	tmp->fail = NULL;
	tmp->kind = idx ++;
	return tmp;
}

void insert(Trie *root, char *s, int len, int k) {
	Trie *p = root;
	for(int i = 0; i < len; i ++) {
		if(p->next[s[i] - 'a'] == NULL) p->next[s[i] - 'a'] = NewNode();
		p = p->next[s[i] - 'a'];
	}
	p->isword = h[k];
}

void build_fail(Trie *root) {
	int head = 0, tail = 0;
	que[tail ++] = root;
	root->fail = NULL;
	while(head < tail) {
		Trie *tmp = que[head ++];
		for(int i = 0; i < 26; i ++) {
			if(tmp->next[i]) {
				if(tmp == root) tmp->next[i]->fail = root;
				else {
					Trie *p = tmp->fail;
					while(p != NULL) {
						if(p->next[i]) {
							tmp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if(p == NULL) tmp->next[i]->fail = root;
				}
				if(tmp->next[i]->fail->isword) tmp->next[i]->isword += tmp->next[i]->fail->isword;
				que[tail ++] = tmp->next[i];
			} 
			else if(tmp == root) tmp->next[i] = root;
			else tmp->next[i] = tmp->fail->next[i];
		}
	}
}

void gao() {
	int ret = 0;
	mem(dp, -1);
	dp[0][0] = 0;
	for(int i = 0; i <= n; i ++) for(int j = 0; j < idx; j ++) path[i][j].clear();
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < idx; j ++) {
			if(dp[i][j] == -1) continue;
			for(int k = 0; k < 26; k ++) {
				int cur = s[j].next[k]->kind;
				if(dp[i][j] + s[cur].isword > dp[i+1][cur]) {
					dp[i+1][cur] = dp[i][j] + s[cur].isword;
					path[i+1][cur] = path[i][j] + (char)(k + 'a');
				} else if(dp[i][j] + s[cur].isword == dp[i+1][cur] && path[i][j] + (char)(k + 'a') < path[i+1][cur]) {
					path[i+1][cur] = path[i][j] + (char)(k + 'a');
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++) for(int j = 0; j < idx; j ++) ret = max(ret, dp[i][j]);
	if(ret == 0) {
		puts("");
		return;
	}
	string str = " ";
	for(int i = 1; i <= n; i ++) for(int j = 0; j < idx; j ++)
		if(dp[i][j] == ret && (str == " " || (path[i][j].size() < str.size() || (path[i][j].size() == str.size() && path[i][j] < str)))) 
			str = path[i][j];  
    cout << str << endl;  
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	idx = 0;
    	Trie *root = NewNode();
    	sii(n, m);
    	for(int i = 1; i <= m; i ++) scanf("%s", str[i]);
    	for(int i = 1; i <= m; i ++) {
    		si(h[i]);
    		insert(root, str[i], strlen(str[i]), i);
    	}
    	build_fail(root);
    	gao();
    }
    
    return 0;
}
