// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 6e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, a[N];

// Imp
void init() {
	int p2 = 1, p3 = 1, p5 = 1, p7 = 1, num = 1;
	a[1] = 1;
	while(num <= 5842) {
		int nxt = min(min(a[p2] * 2, a[p3] * 3), min(a[p5] * 5, a[p7] * 7));
		if(nxt == a[p2] * 2) p2 ++;
		if(nxt == a[p3] * 3) p3 ++;
		if(nxt == a[p5] * 5) p5 ++;
		if(nxt == a[p7] * 7) p7 ++;
		a[++num] = nxt;
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    init();
    while(si(n), n)  
    {  
        if(n%10 == 1&&n%100!=11)  
        printf("The %dst humble number is ",n);  
        else if(n%10 == 2&&n%100!=12)  
        printf("The %dnd humble number is ",n);  
        else if(n%10 == 3&&n%100!=13)  
        printf("The %drd humble number is ",n);  
        else  
        printf("The %dth humble number is ",n);  
        printf("%d.\n",a[n]);  
    }      
    
    
    return 0;
}