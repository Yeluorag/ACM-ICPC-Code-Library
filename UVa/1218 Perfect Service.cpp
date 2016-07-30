#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=10005;
const int inf=1<<20;

int n,a,b,dp[maxn][3],f[maxn];
vector<int> son[maxn];

void dfs(int u){
    int len=son[u].size();
    f[u]=1;
    dp[u][0]=1;
    dp[u][1]=0;
    dp[u][2]=inf;
    vector<int> temp;
    for(int i=0;i<len;i++){
        int v=son[u][i];
        if(f[v]) continue;
        dfs(v);
        temp.push_back(v);
        dp[u][0]+=min(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][2];
    }
    for(int i=0;i<temp.size();i++){
        int v=temp[i];
        dp[u][2]=min(dp[u][2],dp[u][1]-dp[v][2]+dp[v][0]);
    }
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        if(n==-1)break;
        if(n==0)scanf("%d",&n);
        memset(f,0,sizeof(f));
        for(int i=0;i<maxn;i++)son[i].clear();
        for(int i=0;i<n-1;i++) {
            scanf("%d%d",&a,&b);
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dfs(1);
        int ans=min(dp[1][0],dp[1][2]);
        printf("%d\n",ans);
    }
    
    return 0;
}


