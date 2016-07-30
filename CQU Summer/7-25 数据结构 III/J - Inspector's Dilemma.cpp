#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int v,e,t,res,ans,cnt,connect,cas=0;
int flag[1005][1005],vis[1005],out[1005];
vector<int> g[1005];

void dfs(int u){
    int len=g[u].size();
    if(!vis[u]){
        connect+=len%2;
        vis[u]=1;
    }
    for(int i=0;i<len;i++){
        int v=g[u][i];
        if(flag[u][v]) continue;
        res=1;
        flag[u][v]=flag[v][u]=1;
        dfs(v);
    }
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&v,&e,&t)!=EOF){
        if(!v&&!e&&!t) break;
        int x,y;
        connect=0;
        ans=0;
        memset(flag,0,sizeof(flag));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<1001;i++) g[i].clear();
        for(int i=0;i<e;i++){
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=v;i++){
            res=0;
            connect=0;
            dfs(i);
            if(res)ans+=max(connect,2);
        }
//        for(int i=1;i<=v;i++)
//            if(in[i]!=out[i])connect++;
        ans/=2;
//        connect=max(cnt,connect);
        if(!ans) ans++;
        printf("Case %d: %d\n",++cas,(e+ans-1)*t);
        
    }
    return 0;
}