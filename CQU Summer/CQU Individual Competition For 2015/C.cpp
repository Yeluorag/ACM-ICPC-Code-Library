// Header.
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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, l;
multiset<int> s;

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
// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	s.clear();
    	multiset<int>:: iterator iteup, itedown;
    	sii(l, n);
    	int pos = 0, dir = 1;
    	LL ans = 0;
    	s.insert(inf), s.insert(-inf);
    	rep(i, n) {
    		int m = Scan();
    		if(!m) {
    			int x = Scan();
    			s.insert(x);
    		} else {
    			iteup = s.upper_bound(pos);
    			itedown = iteup;
    			itedown --;
    			int ur = *iteup, ul = *itedown;
    			if(pos == ur) {
    				s.erase(iteup);
    				continue;
    			} else if(pos == ul) {
    				s.erase(itedown);
    				continue;
    			}
    			int al = abs(pos - ul), ar = abs(pos - ur);
	    		if(ul == -inf && ur == inf) continue;
	    		if(ul == -inf) {
	    			ans += ar;
	    			s.erase(iteup);
	    			pos = ur;
	    			dir = 1;
	    		} else if(ur == inf) {
	    			ans += al;
	    			s.erase(itedown);
	    			pos = ul;
	    			dir = -1;
	    		} else {
	    			if(al < ar) {
	    				ans += al;
	    				s.erase(itedown);
	    				pos = ul;
	    				dir = -1;
	    			} else if(al > ar) {
	    				ans += ar;
	    				s.erase(iteup);
	    				pos = ur;
	    				dir = 1;
	    			} else {
	    				if(dir == 1) {
	    					ans += ar;
	    					s.erase(iteup);
	    					pos = ur;
	    				} else {
	    					ans += al;
	    					s.erase(itedown);
	    					pos = ul;
	    				}
	    			}
	    		}
    		}
    		
    	}
    	printf("Case %d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}