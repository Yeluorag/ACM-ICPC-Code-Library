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
const int N = 10000 + 5;

vector< pair <int, string> > res;
int n;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    cin >> n;
    rep(i, n) {
    	string s;
    	cin >> s;
    	int x, y, score = 0;
    	cin >> x >> y;
    	score += 100 * x - 50 * y;
    	rep(j, 5) {
    		int p;
    		cin >> p;
    		score += p;
    	}
    	res.push_back(make_pair(score, s));
    }
    sort(res.rbegin(), res.rend());
    cout << res[0].second << endl;
    
    return 0;
}