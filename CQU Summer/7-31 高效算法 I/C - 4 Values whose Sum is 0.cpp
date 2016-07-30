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
const int N = 4000 + 1;

int n, T, ans, idx, a[N], b[N], c[N], d[N], sum1[N * N], sum2[N * N];


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    int i, j;
    cin >> T;
    while (T -- ) {
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i ++) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++)
                sum1[i * n + j] = a[i] + b[j];
        sort(sum1, sum1 + n * n);
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++)
                sum2[i * n + j] = c[i] + d[j];
        sort(sum2, sum2 + n * n);
        int p = n * n - 1;
        for(i = 0; i < n * n; i ++) {
            while(p >= 0 && (sum1[i] +sum2[p] > 0)) p --;
            if(p < 0) break;
            int temp = p;
            while(temp >= 0 && (sum1[i] + sum2[temp] == 0)){
                ans++; temp--;
            }  
        }
        printf("%d\n", ans);
        if(T) puts("");
    }
    
    
    return 0;
}