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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;
char s[N];

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
  
    while(gets(s)){  
        printf("Case %d: ", ++ cas);  
        int len = strlen(s);  
        if(s[1] == ' ') puts("UNIQUE");
        else {  
            if(s[1] == '#') {  
                if(s[0] == 'G') printf("Ab");  
                else printf("%cb",s[0]+1);  
            } else if(s[1] == 'b') {  
                if(s[0] == 'A') printf("G#");  
                else printf("%c#",s[0]-1);  
            }  
            REP(i, 2, len) putchar(s[i]); 
            puts(""); 
        }  
    }  

    return 0;
}