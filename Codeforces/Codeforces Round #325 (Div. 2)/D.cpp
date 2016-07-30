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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k, ans;
char maz[5][30];
node hero, train[30];
struct tra {
	int len, x, y;
};
struct node {
	int x, y;
	tra train[30];
};
void bfs() {
	queue<node> que;
	que.push(hero);
	while(!que.empty()) {
		node u = que.front(); que.pop();
		if(u.y == n - 1) {
			ans = 1;
			break;
		}
		node nxt;
		int nx = u.x - 1, ny = u.y;
		if(nx >= 0 && nx < 3) {
			nxt.x = nx, nxt.y = ny;
			int flag = 1;
			rep(i, 30) {
				nxt.train[i].x = u.train[i].x;
				nxt.train[i].y = (u.train[i].y - 2 + n) % n;
				nxt.train[i].len = u.train[i].len;
				int uy = nxt.train[i].y, ul = nxt.train[i].len
				if(nx == nxt.train[i].x) {
					if(uy + ul < n) {
						if(ny >= uy && ny <= uy + ul) flag = 0;
					} else {
						if(ny <= (uy + ul + n) % n) flag = 0;
					}
				}
			}
			if(flag) que.push(nxt);
		}
	}
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, k);
    	ans = 0;
    	rep(i, 30) hero.train[i].len = -1;
    	rep(i, 3) { 
    		scanf("%s", maz[i]);
    		rep(j, n) {
    			if(maz[i][j] == 's') {
    				hero.x = i; 
    				hero.y = j;
    			}
    			if(maz[i][j] >= 'A' && maz[i][j] <= 'Z') {
    				char c = maz[i][j];
    				if(hero.train[c - 'A'].len == -1) {
    					int cnt = 0;
    					while(maz[i][(j + cnt) % n] != '.') cnt ++;
    					hero.train[c - 'A'].len = cnt;
    					hero.train[c - 'A'].x = i;
    					hero.train[c - 'A'].y = j;
    				}
    			}
    		}
    	}
    	bfs();
    	printf("%s\n", ans ? "YES" : "NO");
    }
    
    return 0;
}