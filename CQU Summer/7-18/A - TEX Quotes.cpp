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
const int maxn = 10000 + 5;

int n = 1;
char c;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);  
    
    while((c = getchar()) != EOF) {
    	if(c == '"') {
    		printf("%s", n ? "``" : "''");
    		n ^= 1;
    	} else putchar(c);
    }
    
    return 0;
}