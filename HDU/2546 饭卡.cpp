#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[1005],dp[1005];
int main(){
   freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        if(m<5) printf("%d\n",m);
        else{
            sort(a,a+n);
            int temp=a[n-1];
            for(int i=0;i<n-1;i++) for(int j=m-5;j>=a[i];j--) dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            printf("%d\n",m-temp-dp[m-5]);
        }
    }
    return 0;
}
