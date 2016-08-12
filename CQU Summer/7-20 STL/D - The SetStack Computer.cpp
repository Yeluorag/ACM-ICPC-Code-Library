// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
typedef set<int> Set;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, hn;
stack<Set> st;
map<Set, int> mp;
// Imp
void hashadd(Set u) {
	if(mp.count(u)) return;
	mp[u] = hn ++;
}

void putsize() {
	if(st.empty()) return;
	put((int)st.top().size());
}

void sf_push() {
	Set u;
	hashadd(u);
	st.push(u);
}

void sf_dup() {
	Set u = st.top();
	st.push(u);
}

void sf_union() {
	Set f = st.top(); st.pop();
	Set u = st.top(); st.pop();

	for(Set::iterator ite = f.begin(); ite != f.end(); ite ++) u.insert(*ite);
	hashadd(u);
	st.push(u);
}

void sf_inct() {
	Set u;
	Set f = st.top(); st.pop();
	Set s = st.top(); st.pop();

	for(Set::iterator ite = f.begin(); ite != f.end(); ite ++) {
		if(s.count(*ite)) u.insert(*ite);
	}

	hashadd(u);
	st.push(u);
}

void sf_add() {
	Set f = st.top(); st.pop();
	Set s = st.top(); st.pop();

	s.insert(mp[f]);
	hashadd(s);
	st.push(s);
}

void solve() {
	char op[10];
	ss(op);
	switch(op[0]) {
		case 'P': sf_push(); break;
		case 'D': sf_dup(); break;
		case 'U': sf_union(); break;
		case 'I': sf_inct(); break;
		case 'A': sf_add(); break;
	}
	putsize();
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	hn = 0;
    	mp.clear();
    	while(!st.empty()) st.pop();
    	si(n);
    	while(n --) solve();
    	printf("***\n");
    }
    
    return 0;
}