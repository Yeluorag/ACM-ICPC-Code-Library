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
int n, m;

// Imp


typedef struct _node  
{  
    int  id;  
    char str[12];  
}node;  
  
node data[101];  
char maps[12][12];  
int  size[12][12];  
  
int cmp(node a, node b)  
{  
    return a.id < b.id;  
}  
  
int main()  
{  
    int row,column,times = 1;  
    while (cin >> row && row) {  
        cin >> column;  
        for (int i = 0; i < row; ++ i)  
            cin >> maps[i];  
        int id = 1;  
        for (int i = 0; i < row; ++ i)  
            for (int j = 0; j < column; ++ j)  
                if (maps[i][j] != '*' && (!i || !j || maps[i-1][j] == '*' || maps[i][j-1] == '*'))  
                    size[i][j] = id ++;  
                else size[i][j] = 0;  
          
        if  (times > 1) printf("\n");  
        printf("puzzle #%d:\n",times ++);  
        printf("Across\n");  
        for (int i = 0; i < row; ++ i) {  
            int move = 0;  
            while (move < column) {  
                if (size[i][move]) {  
                    printf("%3d.",size[i][move]);  
                    int save = 0;  
                    while (move < column && maps[i][move] != '*')  
                        printf("%c",maps[i][move ++]);  
                    printf("\n");  
                }else move ++;  
            }  
        }  
          
        printf("Down\n");  
        int count = 0;  
        for (int i = 0; i < column; ++ i) {  
            int move = 0;  
            while (move < row) {  
                if (size[move][i]) {  
                    data[count].id = size[move][i];  
                    int save = 0;  
                    while (move < row && maps[move][i] != '*')  
                        data[count].str[save ++] = maps[move ++][i];  
                    data[count ++].str[save ++] = 0;  
                }else move ++;  
            }  
        }  
        sort(data, data+count, cmp);  
        for (int i = 0; i < count; ++ i)  
            printf("%3d.%s\n",data[i].id, data[i].str);  
    }  
    return 0;  
}  