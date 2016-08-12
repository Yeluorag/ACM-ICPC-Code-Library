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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int place[25];  
int st[25][25];  
int top[25];  
  
void init_place( int a )  
{  
    int block,id = place[a];  
    while ( st[id][top[id]] != a ) {  
        block = st[id][top[id] --];  
        place[block] = block;  
        st[block][++ top[block]] = block;  
    }  
}  
  
int  temp[25];  
void pile_a_to_b( int a, int b )  
{  
    int topt = -1,id = place[a],ID = place[b];  
    while ( st[id][top[id]] != a )  
        temp[++ topt] = st[id][top[id] --];  
    place[a] = ID;  
    st[ID][++ top[ID]] = a;  
    top[id] --;  
    while ( topt >= 0 ) {  
        place[temp[topt]] = ID;  
        st[ID][++ top[ID]] = temp[topt --];  
    }  
}  
   
int main()  
{  
#ifdef LOCAL
    IN  //  OUT
#endif
	
    int  n,a,b;  
    char oper[5],type[5];  
    while ( ~scanf("%d",&n) ) {  
        for ( int i = 0 ; i < n ; ++ i ) {  
            st[i][0] = i;  
            place[i] = i;  
            top[i] = 0;  
        }  
        while ( scanf("%s",oper) && oper[0] != 'q' ) {  
            scanf("%d%s%d",&a,type,&b);  
            if ( place[a] == place[b] ) continue;  
            if ( oper[0] == 'm' ) init_place( a );   
            if ( type[1] == 'n' ) init_place( b );  
            pile_a_to_b( a, b );   
        }   
          
        for ( int i = 0 ; i < n ; ++ i ) {  
            printf("%d:",i);  
            int now = 0;  
            while ( now <= top[i] )  
                printf(" %d",st[i][now ++]);  
            puts(""); 
        }  
    }  
    return 0;  
}  