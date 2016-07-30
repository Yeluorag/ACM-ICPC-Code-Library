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
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30;
const int N = 1e5 + 5;

int T, cas = 0;
int n, a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> T;
    while(T --) {
    	scanf("%d", &n);
    	int cnt = 0;
    	rep(i, n) scanf("%d", &a[i]);
    	rep(i, n) rep(j, i) if(a[j] > a[i]) cnt ++;
    	printf("%s\n", (!(cnt & 1) || !(n & 1)) ? "possible" : "impossible");
    }
    return 0;
}