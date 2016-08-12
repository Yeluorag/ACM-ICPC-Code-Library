#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int isp[105];
int a[15][2],f[15],n,ans,hand[15];
void dfs(int cur){
    if(cur==n)
        if(__gcd(a[hand[cur-1]][1],a[hand[0]][0])==1) ans++;

    for(int i=1;i<n;i++) {
        if(!f[i]&&(__gcd(a[i][0],a[hand[cur-1]][1])==1)){
            f[i]=1;
            hand[cur]=i;
            dfs(cur+1);
            f[i]=0;
        }
    }

}

int main(){
    //freopen("/Users/apple/input.txt","r",stdin);

    while(scanf("%d",&n)!=EOF){
        memset(hand,0,sizeof(hand));
        memset(a,-1,sizeof(a));
        memset(f,0,sizeof(f));
        ans=0;
        for(int i=0;i<n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
        hand[0]=0;
        dfs(1);
        if(n==1)ans=0;
        printf("%d\n",ans);
    }
    return 0;
}