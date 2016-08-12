#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int maz[25][25],vis[25][25],crs[25][25];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int T,m,n,k,ans;
struct node{
    int x,y;
    int cost,cross;
};

void bfs(){
    node st;
    ans=-1;
    st.x=1;st.y=1;st.cost=0;st.cross=0;
    queue<node>que;
    que.push(st);
    while(!que.empty()){
        node temp=que.front();que.pop();
//        printf("[%d][%d]:cost:%d cross:%d\n",temp.x,temp.y,temp.cost,temp.cross);
        if(temp.x==m&&temp.y==n){
            ans=temp.cost;
            return;
        }
        for(int i=0;i<4;i++){
            int nx=temp.x+dir[i][0],ny=temp.y+dir[i][1];
            int nxtCross=temp.cross;
            if(nx<1||ny<1||nx>m||ny>n) continue;
            if(maz[nx][ny]) nxtCross++;
            else nxtCross=0;
            if(vis[nx][ny]&&nxtCross>=crs[nx][ny]) continue;
            if(nxtCross<=k){
                node nxt;
                nxt.x=nx;nxt.y=ny;
                nxt.cross=nxtCross;
                nxt.cost=temp.cost+1;
                vis[nx][ny]=1;
                crs[nx][ny]=nxtCross;
                que.push(nxt);
            }
        }
    }
}
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d%d",&m,&n);
        scanf("%d",&k);
        memset(maz,0,sizeof(maz));
        memset(vis,0,sizeof(vis));
        memset(crs,0x3f,sizeof(crs));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&maz[i][j]);
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}