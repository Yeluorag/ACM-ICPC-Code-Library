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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k;
int sum[N], a[N], que[N];
int Scan() {         // num = Scan();
    int res = 0, flag = 0;  
    char ch;  
    if((ch = getchar()) == '-') flag = 1;  
    else if(ch >= '0' && ch <= '9') res = ch - '0';  
    while((ch = getchar()) >= '0' && ch <= '9')  
        res = res * 10 + (ch - '0');  
    return flag ? -res : res;  
}  
  
void Out(int a) {    //  Out(num);
    if(a < 0) { putchar('-'); a = -a; }  
    if(a >= 10) Out(a / 10);  
    putchar(a % 10 + '0');  
} 

bool check(LL x1, LL x2, LL x3) {
	return (sum[x3] - sum[x2]) * (x2 - x1) <= (sum[x2] - sum[x1]) * (x3 - x2);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, k) != EOF) {
    	for(int i = 1; i <= n; i ++) {
    		a[i] = Scan();
    		sum[i] = sum[i-1] + a[i];
    	}
    	int head = 0, rear = -1;
    	double ans = 0.0;
    	for(int i = k; i <= n; i ++) {
    		while(head < rear && check(que[rear - 1], que[rear], i - k))
    			-- rear;
    		que[++rear] = i - k;

    		while(head < rear && check(que[head + 1], que[head], i))
    			++ head;

    		ans = max(ans, (sum[i] - sum[ que[head] ]) * 1.0 / (i - que[head]));
    	}
    	printf("%.2f\n", ans);
    }
    
    return 0;
}