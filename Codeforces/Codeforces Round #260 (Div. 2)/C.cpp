#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int  a[100005];
long long dp[100005],f[100005];
int main()
{
    int n,ma=0;
    long long ans=0;
    memset(f,0,sizeof(f));
	memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%I64d",&a[i]);
        f[a[i]]+=(long long)a[i];
        ma=max(ma,a[i]);
    }
	dp[1]=f[1];
    for(int i=2;i<=ma;i++){
        dp[i]=max(dp[i-1],dp[i-2]+f[i]);
    }
    printf("%I64d\n",dp[ma]);
    return 0;
}
