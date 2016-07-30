#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k, cur, num;
int a[N];
struct Elem {
	int val, pos;
}maxque[N], minque[N];
int maxhead, minhead, maxtail, mintail;
int maxans[N], minans[N];
int Scan() {         // num = Scan();
    int res = 0, flag = 0;  
    char ch;  
    if((ch = getchar()) == '-') flag = 1;  
    else if(ch >= '0' && ch <= '9') res = ch - '0';  
    while((ch = getchar()) >= '0' && ch <= '9')  
        res = res * 10 + (ch - '0');  
    return flag ? -res : res;  
}  

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, k) != EOF) {
    	minhead = mintail = maxhead = maxtail = cur = 0;
    	rep(i, k) {
    		num = Scan();

    		while(minhead < mintail && minque[mintail - 1].val >= num) mintail --;
    		minque[mintail].val = num;
    		minque[mintail].pos = i;
    		mintail ++;

    		while(maxhead < maxtail && maxque[maxtail - 1].val <= num) maxtail --;
    		maxque[maxtail].val = num;
    		maxque[maxtail].pos = i;
    		maxtail ++;
    	}
    	REP(i, k, n) {
    		minans[cur] = minque[minhead].val;
    		maxans[cur] = maxque[maxhead].val;
    		cur ++;

    		num = Scan();

    		while(minhead < mintail && i - minque[minhead].pos >= k) minhead ++;
    		while(minhead < mintail && minque[mintail - 1].val >= num) mintail --;
    		minque[mintail].val = num;
    		minque[mintail].pos = i;
    		mintail ++;

    		while(maxhead < maxtail && i - maxque[maxhead].pos >= k) maxhead ++;
    		while(maxhead < maxtail && maxque[maxtail - 1].val <= num) maxtail --;
    		maxque[maxtail].val = num;
    		maxque[maxtail].pos = i;
    		maxtail ++;
    	}

    	minans[cur] = minque[minhead].val;
    	maxans[cur] = maxque[maxhead].val;
    	cur ++;

    	rep(i, cur) printf("%d%c", minans[i], i == cur - 1 ? '\n' : ' ');
    	rep(i, cur) printf("%d%c", maxans[i], i == cur - 1 ? '\n' : ' ');
    }
    
    return 0;
}