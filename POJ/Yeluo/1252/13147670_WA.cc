#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[1100],value[10];
const int INF=1000000;
int main()
{
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<6;i++)
            cin>>value[i];
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<6;i++)
            for(int j=value[i];j<=1000;j++)
                dp[j]=min(dp[j],dp[j-value[i]]+1);
        for(int i=0;i<6;i++)
            for(int j=1000;j>=0;j--)
                dp[j]=min(dp[j],dp[j+value[i]]+1);
        int max_n=0;
        double sum=0;
        for(int i=1;i<=100;i++){
            sum+=dp[i];
            max_n=max(max_n,dp[i]);
        }
        printf("%.2lf %d\n",sum/100,max_n);
    }
    return 0;
}
