#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=100000000;
int a[105][105],m,n,dp[105][105],c[105][105],ans[105];
int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	int T,w=0;
	cin>>T;
	while(w<T){
		for(int i=0;i<105;i++)for(int j=0;j<105;j++)dp[i][j]=INF;
		memset(c,0,sizeof(c));
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			for(int i=0;i<n;i++)
				scanf("%d",&a[m][n]);
		printf("Case %d\n",++w);
		for(int i=0;i<n;i++)dp[0][i]=a[0][i];
		for(int i=1;i<m;i++){
			for(int j=0;j<n;j++){
				for(int k=-1;k<2;k++){
					int x=j+k;
					if(x<0||x==n)continue;
					if(dp[i-1][x]+a[i][j]<=dp[i][j]){
						dp[i][j]=dp[i-1][x]+a[i][j];
						c[i][j]=x;
					}
				}
			}
		}
		int res=0,temp=dp[m-1][0],y;
		for(int i=1;i<n;i++)if(dp[m-1][i]<=temp)res=i;
		ans[m-1]=res;
		y=c[m-1][res];
		for(int i=n-1;i>=0;i--){
			ans[i]=y;
			y=c[i][y];
		}
		for(int i=0;i<m;i++){
			printf("%d",ans[i]);
			if(i==m-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}