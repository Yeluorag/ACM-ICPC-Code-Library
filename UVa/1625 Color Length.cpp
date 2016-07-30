#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=1<<30;

int T,n,m;
int dp[5005][5005],cnt[5005][5005],first[27][2],last[27][2];
char a[5005],b[5005];

void init(){
    memset(last, -1, sizeof(last));
    for (int i=0; i<27; i++) first[i][0]=first[i][1]=INF;
    n=strlen(a);
    m=strlen(b);
    for(int i=0;i<n;i++){
        if(first[a[i]-'A'][0]==INF) first[a[i]-'A'][0]=i;;
        last[a[i]-'A'][0]=i;
    }
    for(int i=0;i<m;i++){
        if(first[b[i]-'A'][1]==INF) first[b[i]-'A'][1]=i;;
        last[b[i]-'A'][1]=i;
    }
    for(int i=0;i<=n;i++){
        int temp=0,k1=-1,k2=-1;
        for(int j=0;j<=m;j++){
            if(i){
                temp=cnt[i-1][0];
                k1=a[i-1]-'A';
                if(first[k1][0]==i-1&&first[k1][1]>j-1) temp++;
                if(last[k1][0]<=i-1&&last[k1][1]<=j-1) temp--;
            }
            if(j){
                temp=cnt[i][j-1];
                k2=b[j-1]-'A';
                if(first[k2][0]>i-1&&first[k2][1]==j-1) temp++;
                if(last[k2][0]<=i-1&&last[k2][1]<=j-1) temp--;
            }
            cnt[i][j]=temp;
        }
    }
}

int main(){
//        freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%s",a);
        scanf("%s",b);
        init();
        dp[0][0]=0;
        for (int i=1; i<=m; i++) dp[0][i]=dp[0][i-1]+cnt[0][i];
        for (int i=1; i<=n; i++) dp[i][0]=dp[i-1][0]+cnt[i][0];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cnt[i][j];
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
