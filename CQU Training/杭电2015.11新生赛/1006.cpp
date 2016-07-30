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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const int M = 10;
int T, cas = 0;
int n, m;
int al, as;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	while(cin >> n){
        as = al = n;
        for(int i = 2; i <= (int)sqrt(n + 0.5); i++){
            int k = i, x = n;
            while(x % k == 0){
                x /= k;
                k ++;
            }
            k --;
            if(k - i > al - as || (k - i == al - as && k < al)){
                as = i;
                al = k;
            }
        }
        printf("%d\n%d", al - as + 1, as);
        for(int i = as + 1; i <= al;i++) printf("*%d",i);
        puts("");
    }
    
    return 0;
}