// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define maxn 100
#define display_limit 50
#define max_INT 10000
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e4, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;

// Imp

int r[3003],u[3003],s[3003];  
  
int main()  
{ 
    int n,m,t;  
    while (cin >> n >> m) {  
        t = n;  
        memset(r, 0, sizeof(r));  
        memset(u, 0, sizeof(u));  
        int count = 0;  
        r[count ++] = n/m;  
        n = n%m;  
        while (!u[n] && n) {  
            u[n] = count;  
            s[count] = n;  
            r[count ++] = 10*n/m;  
            n = 10*n%m;  
        }  
        printf("%d/%d = %d",t,m,r[0]);  
        printf(".");  
        for (int i = 1 ; i < count && i <= 50 ; ++ i) {  
            if (n && s[i] == n) printf("(");  
            printf("%d",r[i]);  
        }  
        if (!n) printf("(0");  
        if (count > 50) printf("...");  
        printf(")\n");  
        printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);  
    }  
    return 0;  
} 