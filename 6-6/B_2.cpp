#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

const int N = 1e5 + 5;
int n, m, v[N], r[N], c[N];

struct E
{
	int to, cost;	
};

vector<E> G[N];
map<int,int> mp;

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    int t; scanf("%d", &t);
    int kase = 0;
    while(t--){
    	for(int i = 1; i <= n; ++i) G[i].clear();
    	mp.clear();
    	vector<int> p; p.push_back(1);
    	for(int i = 1; i <= n; ++i){
    		scanf("%d%d%d", v + i, r + i, c + i);
    		p.push_back(v[i]), p.push_back(r[i]);
    	}
    	sort(p.begin(), p.end());
    	p.erase(unique(p.begin(), p.end()), p.begin());
    	for(int i = 0; i < p.size(); ++i){
    		mp[p[i]] = i + 1;
    	}

    	
    }
    return 0;
}
