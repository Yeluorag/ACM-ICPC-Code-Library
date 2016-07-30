#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k,a[10005],dp[10005];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&k),k){
        int flag=1;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
            if(a[i]>=0)flag=0;
            dp[i]=a[i];
            if(i>0&&dp[i-1]>0)dp[i]+=dp[i-1];
        }
        int l=0,r=0,lt=0,rt=0,ans=dp[0];
        for(int i=0;i<k;i++){
            if(dp[i]<0)lt=i+1;
            if(dp[i]>=0)rt=i;
            if(dp[i]>ans){l=lt;r=rt;ans=dp[i];}
        }
        if(flag){l=0;r=k-1;ans=0;}
        printf("%d %d %d\n",ans,a[l],a[r]);
    }
    return 0;
}
