#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=400005;
const int inf=1<<30;
struct node{
    int v,c,nxt;
}edge[maxn<<1];
int head[maxn],vis[maxn],n,m,tot;
int d[maxn],ans[maxn];

void addedge(int u,int v,int c,int *h){
    edge[tot].v=v;
    edge[tot].c=c;
    edge[tot].nxt=h[u];
    h[u]=tot++;
}

void bfs(){
    memset(d,-1,sizeof(d));
    queue<int>que;
    d[n]=0;
    que.push(n);
    while(!que.empty()){
        int u=que.front();que.pop();
        if(u==1)break;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            que.push(v);
        }
    }
    
}

void bfs2(){
    bfs();
    queue<int>que;
    memset(vis,0,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    que.push(1);
    while(!que.empty()){
        int u=que.front();que.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            if(d[v]==d[u]-1&&edge[i].c<ans[d[1]-d[v]])
                ans[d[1]-d[v]]=edge[i].c;
        }
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            if(d[v]==d[u]-1&&edge[i].c==ans[d[1]-d[v]]){
                que.push(v);
            }
        }
    }
    printf("%d\n",d[1]);
    for(int i=1;i<d[1];i++) printf("%d ",ans[i]);
    printf("%d\n",ans[d[1]]);
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while( scanf("%d%d",&n,&m)==2){
        int u,v,c;
        tot=0;
        memset(head,-1,sizeof(head));
        
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c,head);
            addedge(v,u,c,head);
        }
        bfs2();
    }
    return 0;
}