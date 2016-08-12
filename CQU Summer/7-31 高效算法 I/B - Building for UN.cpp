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
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 10000 + 5;

int n;
char maz[2][55][55];
char nation[55];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    for(int i = 0;i < 52; i ++) nation[i] = i < 26 ? 'A' + i : 'a' + i - 26;
    while(scanf("%d", &n) != EOF){
        mem(maz, '\0');
        for(int i = 0; i < 2; i ++) for(int j = 0; j < n; j ++) for(int k = 0; k < n; k ++) maz[i][j][k] = '\0';
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) maz[0][i][j] = nation[i];
        for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) maz[1][j][i] = nation[i];
        printf("%d %d %d\n", 2, n, n);
        for(int i = 0; i < n; i ++) printf("%s\n", maz[0][i]);
        puts("");
        for(int i = 0; i < n; i ++) printf("%s\n", maz[1][i]);
        puts("");
    }
    
    return 0;
}