#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[8]={-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8]={1, -1, 2, 2, 1, -1, -2, -2};
char st,gt;
int sx,gx,sy,gy,ans;

struct node{
    int x, y;
    int move;
};

void bfs(){
    queue<node> que;
    node start;
    start.x=sx;start.y=sy;start.move=0;
    que.push(start);
    while(!que.empty()){
        node temp=que.front();que.pop();
        if(temp.x==gx&&temp.y==gy){
            ans=temp.move;
            return;
        }
        for(int i=0;i<8;i++){
            node nxt;
            int nx=temp.x+dx[i],ny=temp.y+dy[i];
            if(nx<1||ny<1||nx>8||ny>8) continue;
            nxt.x=nx;
            nxt.y=ny;
            nxt.move=temp.move+1;
            que.push(nxt);
        }
    }
}
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%c%d %c%d",&st,&sy,&gt,&gy)!=EOF){
        getchar();
        sx=st-'a'+1;gx=gt-'a'+1;
        bfs();
        printf("To get from %c%d to %c%d takes %d knight moves.\n",st,sy,gt,gy,ans);
    }
    return 0;
}