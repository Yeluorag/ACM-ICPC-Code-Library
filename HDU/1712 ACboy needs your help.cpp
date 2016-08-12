#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[105][105],dp[105];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++){
            for(int j=m;j>=0;j--){
                for(int k=0;k<j;k++){
                    dp[j]=max(dp[j],dp[j-k-1]+a[i][k]);
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
