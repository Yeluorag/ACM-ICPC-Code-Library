#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[2100],value[10];
const int INF=20000;
int max(int x,int y){return x>y?x:y;}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i;
        for(i=0;i<6;i++)
            cin>>value[i];
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        int max_n=0,sum=0;
        for(i=0;i<6;i++)
            for(int j=value[i];j<=2000;j++)
                dp[j]=min(dp[j],dp[j-value[i]]+1);
        for(i=0;i<6;i++)
            for(int j=2000;j>=0;j--)
                dp[j]=min(dp[j],dp[j+value[i]]+1);

        for(i=1;i<=100;i++){
            sum+=dp[i];
            max_n=max(max_n,dp[i]);
        }
        printf("%.2lf %d\n",sum/100.0,max_n);
    }
    return 0;
}
