#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int m,n,dp[105][105];
int main(){
	int t;
	freopen("/Users/apple/input.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>m>>n;
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(j-i>=0)dp[i][j]=dp[i-1][j]+dp[i][j-i];
				else dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}