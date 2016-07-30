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
const int N = 1e4 + 5;

int n, m, a[N], dp[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(scanf("%d",&n) != EOF){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        if(m<5) printf("%d\n",m);
        else{
            sort(a,a+n);
            int temp=a[n-1];
            for(int i=0;i<n-1;i++) for(int j=m-5;j>=a[i];j--) dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            printf("%d\n",m-temp-dp[m-5]);
        }
    }
    
    return 0;
}