#define LOCAL
#include <iostream>
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
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 1000000 + 5;

int n, a[N], flag[N], ans = 0;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	std::ios::sync_with_stdio(false);

	mem(flag, 0);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
    	scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int idx = 0;
    for(int i = 0; i < n; i ++) {
    	for(idx; idx <= a[i]; idx ++)
    		flag[idx] = i;
    }
    for(int i = 0; i < n; i ++) {
    	
    }
    return 0;
}