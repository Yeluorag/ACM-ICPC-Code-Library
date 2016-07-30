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
const ll MOD = 1000000007;

ll comb[1005][2010], n, m, k;
void init() {
	for(int i=1;i<1005;i++)
		for(int j=0;j<1005;j++){
			if(j>i)
				comb[i][j]=0;
			else if(!j || i==j)
				comb[i][j]=1;
			else if(j==1 || j==i-1)
				comb[i][j]=i;
			else
				comb[i][j]= (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
}

int main(){
    // freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    init();
    cin >> n >> m >> k;
    printf("%lld\n", (comb[n-1][2*k] * comb[m-1][2*k]) % MOD);
    return 0;
}