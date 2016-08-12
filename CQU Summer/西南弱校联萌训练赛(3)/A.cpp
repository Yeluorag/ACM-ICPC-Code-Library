// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 5e1 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
int vis[N], flag[N];
double dis[N], g[N][N], ans;
struct point{
	int x, y;
}p[N];
struct Edge{
	int u, v;
	double dis;
	bool operator < (const Edge& rhs) const {
		return dis < rhs.dis;
	}
}e[N * N];
// Imp
double Dis(int i, int j) {
	return sqrt((double)(p[i].x - p[j].x) * (p[i].x - p[j].x) + (double)(p[i].y - p[j].y) * (p[i].y - p[j].y));
}

void Prim() {
	mem(vis, 0);
	int u = flag[0];
	rep(i, n) if(!flag[i]) dis[i] = g[u][i];
	double sum = 0.0;
	vis[u] = 1;
	double minc;
	int p;
	REP(i, 1, n - 1) {
		minc = inf;
		rep(j, n) {
			if(!vis[j] && !flag[j] && dis[j] < minc) {
				minc = dis[j];
				p = j;
			}
		}
		sum += minc;
		vis[p] = 1;
		rep(j, n) if(!flag[j]) Min(dis[j], g[p][j]);
	}
	Min(ans, sum);
}

int main(){
#ifdef LOCAL
    IN;
//  OUT;
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	rep(i, n) sii(p[i].x, p[i].y);
    	rep(i, n) rep(j, n) g[i][j] = g[j][i] = Dis(i, j);
    	mem(flag, 0);
    	ans = inf;
    	flag[0] = 1;
    	Prim();
    	REP(i, 1, n) {
    		flag[i-1] = 0, flag[i] = 1;
    		Prim();
    	}
    	printf("%.2lf\n", ans);
    }
    return 0;
}