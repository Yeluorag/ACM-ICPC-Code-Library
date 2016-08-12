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

int cmp(const void *a,const void *b) {  
    return strcmp((char *)a,(char *)b);  
}  
int main() {  
#ifdef LOCAL
    IN // OUT
#endif
	
    int i,j,k,max_len,n;  
    int h_num,l_num,num_len;  
    char str[110][100];  
    while(scanf("%d",&n)!=EOF)  
    {  
        max_len=0;  
        for(i=0;i<n;i++)  
        {  
            scanf("%s",str[i]);  
            if(strlen(str[i])>max_len)  
                max_len=strlen(str[i]);  
        }  
        qsort(str,n,100*sizeof(char),cmp);  
        printf("------------------------------------------------------------\n");  
        h_num=62/(max_len+2);  
        l_num=(n-1)/h_num+1;  
        for(i=0;i<l_num;i++)  
        {  
            for(j=0;j<h_num;j++)  
            {  
                if(j*l_num+i>=n)  
                    break;  
                printf("%s",str[j*l_num+i]);  
                num_len=max_len-strlen(str[j*l_num+i]);  
                for(k=0;k<num_len;k++)  
                {  
                    printf(" ");  
                }  
                if(j!=h_num-1)  
                    printf("  ");  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  