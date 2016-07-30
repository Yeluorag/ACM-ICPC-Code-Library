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
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 10000 + 5;

int a, b, ans;
void Name() {
	ans = a + b;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	std::ios::sync_with_stdio(false);

    a = 4; b = 5;
    Name();
    cout << ans << endl;
    
    return 0;
}