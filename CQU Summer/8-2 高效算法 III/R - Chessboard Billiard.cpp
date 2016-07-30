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

int n, m;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    cin >> n >> m;
    if(n > m) swap(n, m);
    printf("%d\n", n == 1 ? m : __gcd(n - 1, m - 1) + 1);
    return 0;
}