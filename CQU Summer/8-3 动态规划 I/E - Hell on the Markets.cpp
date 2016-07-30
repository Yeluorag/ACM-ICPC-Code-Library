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
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 100000 + 5;

int n, ans, flag[N];
LL sum;
struct node{
    int num;
    int id;
}a[N];
bool cmp (const node &t1, const node &t2){ return t1.num > t2.num; }
bool Cmp (const node &t1, const node &t2){ return t1.id < t2.id; }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%d", &n) != EOF) {
        sum = 0; ans = 1;
        mem(flag, -1);
        rep(i, n) {
            int t;
            scanf("%d", &t);
            a[i].num = t;
            sum += t;
            a[i].id = i;
        }
        sort(a, a + n, cmp);
        if(sum % 2) ans = 0;
        if(ans) {
            sum /= 2;
            ans = 0;
            rep(i, n) {
                if(a[i].num <= sum) {
                    flag[a[i].id] = 1;
                    sum -= a[i].num;
                    if(!sum) { ans = 1; break; }
                }
            }
        }
        sort(a, a + n, Cmp);
        puts(ans ? "Yes" : "No");
        if(ans) rep(i, n) printf("%d%c", flag[i], i == n - 1 ? '\n' : ' ');
    }
    
    return 0;
}