#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,cnt,ans,flag[1005][1005][5];
char ch='\\';
char maz[1005][1005],s[1005][1005];
int dir;
bool check(int a,int b){
    if(a>=0 && a<n && b>=0 && b<m && maz[a][b]!='*') return 1;
    return 0;
}

void dfs(int x,int y,int dx,int dy){
    while (check(x, y)&&!flag[x][y][dir]) {
        if (dx==1&&dy==0) dir=1;
        else if (dx==0&&dy==1) dir=2;
        else if (dx==-1&&dy==0) dir=3;
        else if (dx==0&&dy==-1) dir=4;
        if(s[x][y]=='.'||s[x][y]=='T'){

        }else if(maz[x][y]=='E'){
            cnt++;
            s[x][y]='.';
        }
        flag[x][y][dir]=1;
        if(s[x][y]==ch) {
             if(dx==-dy){
                 dx=-dx;dy=-dy;
             }else if(dx*dy==0){
                 int t=dx;
                 dx=dy;
                 dy=t;
             }else return;
        }else if(s[x][y]=='/'){
             if(dx==dy){
                 dx=-dx;dy=-dy;
             }else if(dx*dy==0){
                 int t=dx;
                 dx=-dy;
                 dy=-t;
             }else return;
        }
        x+=dx;y+=dy;
    }
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
     int tx,ty;
     cin>>n>>m;
     for(int i=0;i<n;i++)
         scanf("%s",maz[i]);
     for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
             if(maz[i][j]=='T'){tx=i;ty=j;}
     for(int dx=-1;dx<=1;dx++){
         for(int dy=-1;dy<=1;dy++){
             if(dx*dy!=0||dx+dy==0)continue;
             memset(flag, 0, sizeof(flag));
             for(int i=0;i<n;i++)
                 for(int j=0;j<m;j++)
                     s[i][j]=maz[i][j];
             cnt=0;
             dfs(tx,ty,dx,dy);
             ans=max(ans,cnt);
         }
     }
     printf("%d\n",ans);
     
     return 0;
}