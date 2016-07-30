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

LL func(LL N){
    LL ten = 1, ans = 0;
    while(N > 0){
        LL x = N % 10;
        if(x != 0){
            ans += x * ten;
            ten *= 10;
        }
        N /= 10;
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    LL A,B;
    
    cin >> A >> B;
    LL C = A + B;
    
    bool ans = (func(C) == func(A) + func(B));
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}