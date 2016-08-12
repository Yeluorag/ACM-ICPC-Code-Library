#include <iostream>
#include <sstream>
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
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = t; i < n; i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 100 + 5;

int n, m, l[N];

int leader (int v) {
	if (l[v] != v)
		l[v] = leader (l[v]);
	return l[v];
}

void unite (int v1, int v2) {
	v1 = leader (v1);
	v2 = leader (v2);
	l[v1] = v2;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    cin >> n >> m;
    if(n != m) {
    	puts("NO");
    	return 0;
    }
    rep(i, n) l[i] = i;
    rep(i, n) {
    	int a, b;
    	scanf("%d%d", &a, &b);
    	a --; b --;
    	unite(a, b);
    }
    rep(i, n - 1) if(leader(i) != leader(i + 1)) {
    	puts("NO");
    	return 0;
    }
    puts("FHTAGN!");
    
    return 0;
}