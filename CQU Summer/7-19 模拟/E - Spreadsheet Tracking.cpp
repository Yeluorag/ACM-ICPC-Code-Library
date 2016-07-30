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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7, MAX = 1e4;
// Macro end

int T, cas = 0;
// Imp

int r,c,n;  
struct cmd  
{  
    string s;  
    int A,a[20];  
    int r1,c1,r2,c2;  
}cmds[MAX];  
  
void save(string str, int i)  
{  
    int A;  
    if(str!="EX"){  
        cin>>A;  
        cmds[i].s = str; cmds[i].A = A;  
        for(int j=0;j<A;j++) cin>>cmds[i].a[j];  
    }  
    else if(str=="EX"){  
        cmds[i].s = str;  
        cin>>cmds[i].r1>>cmds[i].c1>>cmds[i].r2>>cmds[i].c2;  
    }  
}  
  
bool solve(int& x, int& y)  
{  
    int xx,yy;  
    for(int i=0;i<n;i++)  
    {  
        if(cmds[i].s=="DR"){  
            xx = x; yy = y;  
            for(int j=0;j<cmds[i].A;j++){  
                if(cmds[i].a[j]<xx) { x--; }  
                else if(cmds[i].a[j]==xx) { return false;}  
            }  
        }  
        else if(cmds[i].s=="DC"){  
            xx = x; yy = y;  
            for(int j=0;j<cmds[i].A;j++){  
                if(cmds[i].a[j]<yy)  {  y--;}  
                else if(cmds[i].a[j]==yy) { return false;}  
            }  
        }  
        else if(cmds[i].s=="IC"){  
            xx = x; yy = y;  
            for(int j=0;j<cmds[i].A;j++){  
                if(cmds[i].a[j]<=yy) y++;  
            }  
        }  
        else if(cmds[i].s=="IR"){  
            xx = x; yy = y;  
            for(int j=0;j<cmds[i].A;j++){  
                if(cmds[i].a[j]<=xx)  x++;  
            }  
        }  
        else if(cmds[i].s=="EX"){  
            if(x==cmds[i].r1&&y==cmds[i].c1) { x = cmds[i].r2; y =cmds[i].c2;}  
            else if(x==cmds[i].r2&&y==cmds[i].c2) { x = cmds[i].r1; y =cmds[i].c1;}  
        }  
    }  
    return true;  
}  
  
int main()  
{  
    //freopen("512.txt","r",stdin);  
    //freopen("512ans.txt","w",stdout);  
    int icase = 0;  
    while(cin>>r>>c)  
    {  
        if(r==0&&c==0) break;  
        cin>>n;  
        if(icase>0) cout<<endl;  
        for(int i=0;i<n;i++)  
        {  
            string str; cin>>str;  
            save(str,i);  
        }  
        cout<<"Spreadsheet #"<<++icase<<endl;  
        int q; cin>>q;  
        while(q--)  
        {  
            int x,y,xx,yy;  
            cin>>x>>y; xx = x; yy = y;  
            if(solve(x,y)) printf("Cell data in (%d,%d) moved to (%d,%d)\n",xx,yy,x,y);  
            else printf("Cell data in (%d,%d) GONE\n",xx,yy);  
        }  
    }  
    return 0;  
}  