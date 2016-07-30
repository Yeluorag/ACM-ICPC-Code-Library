#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 100000 + 5;

int T[N], num[N], san[N], ls[N * 20], rs[N * 20], sum[N * 20];
int tot, rt, n, m;

void Build(int l, int r, int &rt) {
	rt = ++ tot;
	sum[rt] = 0;
	if(l == r) return;
	int m = (l + r) >> 1;
	Build(l, m, ls[rt]);
	Build(m + 1, r, rs[rt]);
}

void Update(int last, int p, int l, int r, int &rt) {
	rt = ++ tot;
	ls[rt] = ls[last];
	rs[rt] = rs[last];
	sum[rt] = sum[last] + 1;
	if(l == r) return;
	int m = (l + r) >> 1;
	if(p <= m) Update(ls[last], p, l, m, ls[rt]);
	else Update(rs[last], p, m + 1, r, rs[rt]);
}

void Query(int ss, int tt, int l, int r, int k) {

}

void solve() {
	int l, r, k;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &num[i]);
		san[i] = num[i];
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	std::ios::sync_with_stdio(false);

    
    
    return 0;
}