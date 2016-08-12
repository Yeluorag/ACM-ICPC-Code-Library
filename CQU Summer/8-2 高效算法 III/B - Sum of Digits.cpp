#define LOCAL
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
const int N = 100000 + 5;

char num[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    scanf("%s", num);
    int len = strlen(num), ans = 1, sum = 0;
    rep(i, len) sum += num[i] - '0';
    while(sum / 10) {
    	int ret = 0;
    	while(sum) {
    		ret += sum % 10;
    		sum/=10;
    	}
    	sum = ret;
    	ans ++;
    }
    if(len == 1) ans = 0;
    printf("%d\n", ans);
    return 0;
}