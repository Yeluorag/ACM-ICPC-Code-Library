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
typedef long long ll;
const int bound = 100005;

int T, cas = 0;
ll n, s1, v1, s2, v2, ans;
int main(){
//    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    cin >> T;
    while(T--) {
        scanf("%lld", &n);
        scanf("%lld%lld%lld%lld", &s1, &v1, &s2, &v2);
        ans = -1;
        if(n / max(s1, s2) < bound) {
            ll bd1 = n / s1, bd2 = n / s2;
            if(bd1 < bd2) {
                for(ll i = 0; i <= bd1; i++)
                    ans = max(ans, i * v1 + (n - i * s1) / s2 * v2);
            } else {
                for(ll i = 0; i <= bd2; i++)
                    ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
            }
        } else {
            ll cnt = n / (s1 * s2), rest = n % (s1 * s2), ret = -1;
            if(s2 * v1 > s1 * v2) {
                ans = cnt * v1 * s2;
                for(ll i = 0; i <= rest / s1; i++) {
                    ret = max(ret, i * v1 + (rest - i * s1) / s2 * v2);
                }
            } else {
                ans = cnt * v2 * s1;
                for(ll i = 0; i <= rest / s2; i++) {
                    ret = max(ret, i * v2 + (rest - i * s2) / s1 * v1);
                }
            }
            ans += ret;
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}