#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k,s,ans;
int dp[105][105][105],a[105],b[105];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        ans=-1;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<k;i++)scanf("%d%d",&a[i],&b[i]);
        for(int l=1;l<=s;l++){
            for(int i=0;i<k;i++){
                for(int j=0;j<=m;j++){
                    if(j>=b[i])dp[l][i+1][j]=max(dp[l][i][j],dp[l-1][i+1][j-b[i]]+a[i]);
                    else dp[l][i+1][j]=dp[l][i][j];
                }
            }
        }
        for(int l=1;l<=s;l++){
            for(int j=0;j<=m;j++){
                if(dp[l][k][j]>=n){
                    ans=max(ans,m-j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
