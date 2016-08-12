#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int maz[6][6],vis[6][6],pre[105];
struct node{
    int x,y;
}a[105];

void print(int cur){
    int t=pre[cur];
    if(cur==1){
        printf("(0, 0)\n");
        return;
    }
    print(t);
    printf("(%d, %d)\n",a[cur].x,a[cur].y);
}

void bfs(){
    int front=1,rear=2;
    while(front<rear){
        node t=a[front];
        if(t.x==4&&t.y==4) break;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                if((i&&j)||(!i&&!j))continue;
                int nx=t.x+i,ny=t.y+j;
                if(nx<0||ny<0||nx>4||ny>4||vis[nx][ny]||maz[nx][ny]) continue;
                vis[nx][ny]=1;
                a[rear].x=nx;
                a[rear].y=ny;
                pre[rear]=front;
                rear++;
            }
        }
        front++;
    }
    print(front);
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    for(int i=0;i<5;i++)for(int j=0;j<5;j++) scanf("%d",&maz[i][j]);
    memset(vis,0,sizeof(vis));
    bfs();
    return 0;
}