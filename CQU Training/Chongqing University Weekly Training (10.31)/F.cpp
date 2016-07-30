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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
typedef unsigned long long ull;
int T, cas = 0;
int n, m, size;
ull arry[N][N], sum[N][N], temp[N][N], ans[N][N];
char s[10];
ull l;
sturct TrieNode {
	bool mark;
	int id;
	TrieNode *fail, *next[26];
} *root, Node[N];

TrieNode *New_TrieNode() {
	mem(&Node[size], 0);
	Node[size].id = size;
	return &Node[size ++];
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    
    
    return 0;
}