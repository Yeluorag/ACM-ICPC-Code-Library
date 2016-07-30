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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
const int ROW = 10000 + 10;  
const int COL = 10 + 5;  
int n,m;  
map<string, int> IDcache;  
vector<string> Strcache;  
vector<int> Text[ROW]; 
struct node  
{  
    int x,y;  
    node(int x, int y):x(x),y(y) { }  
    bool operator < (const node& r) const { return x<r.x || (x==r.x&&y<r.y); }  
};  
map<node,int> data;  
  
int ID_alloc(string str)  
{  
    if(IDcache.count(str)) return IDcache[str];  
    Strcache.push_back(str);  
    return IDcache[str] = Strcache.size()-1;  
}  
  
void read()  
{  
    string str;  
    char ch = getchar();  
    for(int i=0;i<n;i++)  
    {  
        for(;;)  
        {  
            ch = getchar();  
            if(ch=='\n'||ch=='\r') {  
                if(!str.empty()) Text[i].push_back(ID_alloc(str));  
                str.clear();  break;  
            }  
            if(ch!=',') str += ch;  
            else { Text[i].push_back(ID_alloc(str)); str.clear();}  
         }  
    }  
}  
  
void solve()  
{  
    int x,y,c1,c2;  
    for(c1=0;c1<m;c1++)  
    {  
        for(c2=c1+1;c2<m;c2++)  
        {  
            data.clear();  
            for(int r=0;r<n;r++)  
            {  
                x = Text[r][c1]; y = Text[r][c2];  
                node p(x,y);  
                if(!data.count(p)) data[p] = r;  
                else{  
                    cout<<"NO"<<endl;  
                    cout<<data[p]+1<<" "<<r+1<<endl<<c1+1<<" "<<c2+1<<endl;  
                    return;  
                }  
            }  
        }  
    }  
    cout<<"YES"<<endl;  
}  
  
int main()  
{  
#ifdef LOCAL
    IN // OUT
#endif
    while(cin>>n>>m) {  
        read();  
        solve();  
        for(int i=0;i<n;i++) Text[i].clear();  
        IDcache.clear(); Strcache.clear();  
    }  
    return 0;  
} 