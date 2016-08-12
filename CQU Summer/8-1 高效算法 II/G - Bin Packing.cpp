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

int T, n, m, ans, flag[N];
vector<int> a;
vector<int>::iterator it;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        a.clear();
        scanf("%d%d", &n, &m);
        rep(i, n) {
            int t;
            scanf("%d", &t);
            a.push_back(t);
        }
        ans = 0;
        sort(a.begin(), a.end());
        while(!a.empty()) {
            int x = m - a[0];
            ans ++;
            it = upper_bound(a.begin() + 1, a.end(), x) - 1;
            if(it != a.begin()) {
                a.erase(it);
            }
            a.erase(a.begin());
        }
        printf("%d\n", ans);
        if(T) puts("");
    }
    
    return 0;
}