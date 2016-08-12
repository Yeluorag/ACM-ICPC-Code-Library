#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;

int n,a[105][105],dp[105][105];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    
    while(scanf("%d",&n)!=EOF){
    	memset(dp,0,sizeof(dp));
	    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
	    	scanf("%d",&a[i][j]);
	    	dp[i][j]=a[i][j]+dp[i][j-1];
	    }
	    int ans=-inf;
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<i;j++){
	    		int sum=0;
	    		for(int k=1;k<=n;k++){
	    			sum=max(0,sum);
	    			sum+=dp[k][j]-dp[k][i-1];
	    			ans=max(ans,sum);
	    		}
	    	}
	    }
	    printf("%d\n",ans);
		}
    return 0;
}
