#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define rep(i,t,n) for(int (i)=(t);(i)<(n);(i)++)
int n,m,b,mod,a[505],ans=0,dp[505][505];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    cin>>n>>m>>b>>mod;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    rep(i,0,n)rep(j,1,m+1)rep(k,a[i],b+1)dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
	rep(i,0,b+1)ans=(ans+dp[m][i])%mod;
	cout<<ans<<endl;	
    return 0;
}