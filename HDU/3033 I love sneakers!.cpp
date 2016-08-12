#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,t,v[105],p[105],dp[105][10005],flag;
vector<int> b[15];
int max(int a,int b,int c){
    return a>b?a>c?a:c:b>c?b:c;
}

int main(){
freopen("/Users/apple/input.txt","r",stdin);
	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        flag=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++) {
            scanf("%d%d%d",&t,&p[i],&v[i]);
            b[t].push_back(i);
        }
        for(int i=1;i<=k;i++){
            int len=b[i].size();
            for(int j=0;j<len;j++){
                t=b[i][j];
                for(int l=m;l>=p[t];l--){
                    dp[i][l]=max(dp[i][l],dp[i][l-p[t]]+v[t],dp[i-1][l-p[t]]+v[t]);
                }
            }
        }
        if(dp[k][m]<0)puts("Impossible");
        else printf("%d\n",dp[k][m]);
    }
    return 0;
}
     