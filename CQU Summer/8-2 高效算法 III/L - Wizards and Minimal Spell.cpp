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
#define REP(i, t, n) for(int i = t; i < n; i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 10000000 + 5;

int idx = 0, flag;
char in[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    flag = 1;
    while(gets(in)) {
        int len = strlen(in);
        for(idx = 0; in[idx] == ' '; idx ++);
        if(in[idx] == '#') {
            if(!flag) puts("");
            flag = 1;
            puts(in);
        } else {
            rep(i, len) if(in[i] != ' ') putchar(in[i]);
            flag = 0;
        }
    }
    if(!flag) puts("");
    return 0;
}