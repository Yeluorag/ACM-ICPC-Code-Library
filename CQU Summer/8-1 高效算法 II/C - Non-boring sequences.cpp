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
const int N = 200000 + 5;

int T, n, a[N], l[N], r[N];
map<int, int>mp;

bool search(int ul, int ur) {
    if(ul >= ur) return true;
    int mid = 0;
    for(int i = 0; ul + i <= ur - i; i ++) {
        if((l[ul+i] < ul && r[ul+i] > ur) ||
           (r[ul+i] == ul + i && (l[ul+i] < ul)) ||
           (l[ul+i] == ul + i && (r[ul+i] == ul + i || r[ul+i] > ur))) {
            mid = ul + i;
            break;
        }
        if((l[ur-i] < ul && r[ur-i] > ur) ||
           (r[ur-i] == ur - i && (l[ur-i] < ul)) ||
           (l[ur-i] == ur - i && (r[ur-i] == ur - i || r[ur-i] > ur))) {
            mid = ur - i;
            break;
        }
    }
    if(mid && search(ul, mid - 1) && search(mid + 1, ur)) return true;
    return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", &a[i+1]);
        mp.clear();
        for(int i = 1; i <= n; i ++) {
            if(mp[a[i]]) {
                l[i] = mp[a[i]];
                r[mp[a[i]]] = i;
                r[i] = i;
            } else {
                l[i] = r[i] = i;
            }
            mp[a[i]] = i;
        }
        printf("%s\n", search(1, n) ? "non-boring": "boring");
    }
    
    return 0;
}