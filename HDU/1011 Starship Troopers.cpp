#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=105;

int n,m,a[MAX],b[MAX],vis[MAX],dp[MAX][MAX];
vector<int> son[MAX];
void dfs(int u,int res){
    int temp=(a[u]+19)/20;
    for(int i=temp;i<=m;i++)dp[u][i]=b[u];
    int len=son[u].size();
    for(int i=0;i<len;i++){
        int v=son[u][i];
        if(res>temp)dfs(v,res);
        for(int j=m;j>=temp;j--){
            for(int k=1;k<=j-temp;k++){
                dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k]);
            }
        }
    }
}

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n!=-1||m!=-1){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<MAX;i++)son[i].clear();
        for(int i=0;i<n;i++) scanf("%d%d",&a[i+1],&b[i+1]);
        for(int i=0;i<n-1;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            son[x].push_back(y);
        }
        if(m==0){printf("0\n");continue;}
        dfs(1,m);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}



