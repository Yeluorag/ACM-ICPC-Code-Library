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

int n,m,ans,first;
int d[12][105],nxt[12][105],a[12][105];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(scanf("%d%d", &m, &n) != EOF) {
        ans = inf; first = 0;
        rep(i, m) rep(j, n) scanf("%d", &a[i][j]);
        for(int j = n - 1; j >= 0; j --){
            rep(i, m) {
                if(j == n - 1) d[i][j] = a[i][j];
                else{
                    int dir[3] = { i - 1, i, i + 1 };
                    if(i == 0) dir[0] = m - 1;
                    if(i == m - 1) dir[2] = 0;
                    sort(dir, dir + 3);
                    d[i][j] = inf;
                    rep(k, 3) {
                        int temp = d[dir[k]][j+1] + a[i][j];
                        if(temp < d[i][j]){
                            d[i][j] = temp;
                            nxt[i][j] = dir[k];
                        }
                    }
                }
                if(j == 0 && d[i][j] < ans){
                    ans = d[i][j];
                    first = i;
                }
            }
        }
        rep(i, n - 1){
            printf("%d ", first + 1);
            first = nxt[first][i];
        }
        printf("%d\n%d\n", first + 1, ans);
    }
    
    return 0;
}