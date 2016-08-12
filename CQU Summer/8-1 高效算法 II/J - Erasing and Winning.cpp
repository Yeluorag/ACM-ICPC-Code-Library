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
const int inf = 1 << 30;
const int N = 100000 + 5;

int n, d;
char num[N], ans[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    while(scanf("%d%d", &n, &d) && n && d) {
        int k = 0;
        scanf("%s", num);
        rep(i,n){
            while (k > 0 && i - k < d && ans[k] < num[i])
            k--;
            if (k + d < n) ans[++k] = num[i];
        }
        ans[++k] = '\0';
        puts(ans + 1);
    }
    
    return 0;
}