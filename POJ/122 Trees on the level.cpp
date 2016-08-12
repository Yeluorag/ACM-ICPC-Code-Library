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
const int inf = 0x3f3f3f3f, N = 3e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];
bool failed;
struct Node {
	bool have_value;
	int v;
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL) {}
} root;

Node *newnode() { return new Node(); }

void addndoe(int v, char* s) {
	int len = strlen(s);
	Node* u = root;
	for(int i = 0; i < len; i ++) {
		if(s[i] == 'L') {
			if(u->left == NULL) u->left = newnode();
			u = u->left;
		} else if(s[i] == 'R') {
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}
		if(u->have_value) failed = true;
		u->v = v;
		u->have_value = true;
	}
}

bool read_input() {
	failed = false;
	for(;;) {
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}


#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    
    
    return 0;
}