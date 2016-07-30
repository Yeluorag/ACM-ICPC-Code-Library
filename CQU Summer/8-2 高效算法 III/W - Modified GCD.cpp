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
const int N = 10000 + 5;

int a, b, n, low, high, ans;
vector<int> v;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> a >> b;
    cin >> n;
    int g = __gcd(a, b);
    for(int i = 1; i * i <= g; i ++) if(g % i == 0) {
        v.push_back(i);
        if(g / i > i) v.push_back(g / i);
    }
    sort(ALL(v));
    rep(i, n) {
        ans = -1;
        scanf("%d%d", &low, &high);
        for(int j = v.size() - 1; j >= 0; j --) {
            if(v[j] > high) continue;
            if(v[j] < low) break;
            ans = v[j];
            break;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}