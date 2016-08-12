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

int n, m, a[105][105], cnt[105];
int main(){
    // freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int c, b, ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < m; i++) {
    	scanf("%d%d", &c, &b);
    	a[c][b] = a[b][c] =1;
    	cnt[c] ++; cnt[b] ++;
    }

     while (1) {
        int i;
        vector < int > c;
        for (i = 1; i <= n; i++) {
            if ( cnt[i] == 1 ) {
                c.push_back ( i );
            }
        }
        
        if ( !(int)c.size() ) break;
        ++ans;
        for (i = 0; i < (int)c.size(); i++) {
            cnt[c[i]] = 0;
            for (int j = 1; j <= n; j++) {
                if ( a[c[i]][j] == 1 ) {
                    cnt[j]--;
                    a[c[i]][j] = a[j][c[i]] = 0;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}