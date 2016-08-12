#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[105][105],flag[105],ans[105];
int a,b,n,m,idx;

bool dfs(int u){
    flag[u]=-1;
    for(int i=1;i<=100;i++){
        if(g[u][i]){
            if(flag[i]<0) return false;
            if(!flag[i]&&!dfs(i)) return true;
        }
    }
    flag[u]=1;
    ans[idx--]=u;
    return true;
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    memset(g,0,sizeof(g));
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m) break;
        memset(g,0,sizeof(g));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        idx=n;
        for(int i=1;i<=n;i++)
            if(!flag[i]) dfs(i);
        for(int i=1;i<n;i++) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    
    return 0;
}