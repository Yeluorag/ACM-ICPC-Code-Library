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

int T, cas = 0;
int n, m, k;
int a[N], b[N];
struct node {
	int sum, idx;
	node(int s, int i): sum(s), idx(i) {}
	bool operator < (const node& rhs) const {
		return sum > rhs.sum;
	}
};

void merge(int *A, int *B) {
	priority_queue<node> que;
	for(int i = 0; i < k; i ++) que.push(node(A[i] + B[0], 0));
	for(int i = 0; i < k; i ++) {
		node tmp = que.top(); que.pop();
		A[i] = tmp.sum;
		if(tmp.idx + 1 < k) que.push(node(tmp.sum - B[tmp.idx] + B[tmp.idx + 1], tmp.idx + 1));
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(k) != EOF) {
    	for(int i = 0; i < k; i ++) {
    		for(int j = 0; j < k; j ++) {
    			si(a[j]);
    			if(!i) b[j] = a[j];
    		}
    		sort(a, a + k);
    		if(i) merge(b, a);
    	}
    	for(int i = 0; i < k - 1; i ++) printf("%d ", b[i]);
    	printf("%d\n", b[k-1]);
    }
    
    return 0;
}