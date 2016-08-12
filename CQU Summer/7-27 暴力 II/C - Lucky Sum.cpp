#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll inf = 1000000000000000;

vector<ll> v;
ll l, r;

void init(ll t){
	if(t > inf) return;
	if(t >= l) v.push_back(t);
	init(10 * t + 4);
	init(10 * t + 7);
}

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin >> l >> r;
    ll ans = 0;
    init(0);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
    	ll x = v[i];
    	ans += x * (min(x, r) - l + 1);
    	l = x + 1;
    	if(l > r) break;
    }
    cout << ans << endl;
    return 0;
}