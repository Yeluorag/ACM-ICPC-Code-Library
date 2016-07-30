#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T,m,n,x,y,ans;
int a[1005][1005],dp[1005][1005];  //c[i][j]第i列 竖列和，c[i][j]第i行 横行和
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
    	ans=-1;
    	memset(dp,0,sizeof(dp));
    	memset(a,-1,sizeof(a));
    	scanf("%d%d%d%d",&m,&n,&x,&y);
    	for(int i=1;i<=m;i++){
    		for(int j=1;j<=n;j++){
    			scanf("%d",&a[i][j]);
    			dp[i][j]=a[i][j];
    			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    			if(i>=x&&j>=y){
    				ans=max(ans,dp[i][j]-dp[i-x][j]-dp[i][j-y]+dp[i-x][j-y]);
    			}
    		}
    	}
    	printf("%d\n",ans);
    }
    return 0;
}
