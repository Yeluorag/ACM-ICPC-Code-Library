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

int T, cas = 0;
int n, m;
bool Lock;
deque<int> qr;
queue<int> qb;
vector<string> prg[N];
string s;
int t[N], p[N], var[30], lim;
void run(int i) {
	int rt = lim, v;
	string cur;
	while(rt > 0) {
		cur = prg[i][p[i]];
		if(cur[2] == '=') {
			rt -= t[0];
			v = cur[4] - '0';
			if(cur.size() == 6) v = v * 10 + cur[5] - '0';
			var[cur[0] - 'a'] = v;
		} else if(cur[2] == 'i') {
			rt -= t[1];
			printf("%d: %d\n", i, var[cur[6] - 'a']);
		} else if(cur[2] == 'c') {
			rt -= t[2];
			if(Lock) {
				qb.push(i);
				return;
			} else Lock = true;
		} else if(cur[2] == 'l') {
			Lock = false;
			rt -= t[3];
			if(!qb.empty()) {
				v = qb.front();
				qb.pop();
				qr.push_front(v);
			}
		} else return;
		++ p[i];
	}
	qr.push_back(i);
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < 5; i ++) si(t[i]);
    	si(lim);
    	for(int i = 1; i <= n; i ++) {
    		prg[i].clear();
    		while(getline(cin, s)) {
    			if(s == "") continue;
    			prg[i].push_back(s);
    			if(prg[i].back() == "end") break;
    		}
    		qr.push_back(i);
    	}
    	mem(p, 0);
    	mem(var, 0);
    	while(!qr.empty()) {
    		int cur = qr.front();
    		qr.pop_front();
    		run(cur);
    	}
    	if(T) puts("");
    }
    
    return 0;
}