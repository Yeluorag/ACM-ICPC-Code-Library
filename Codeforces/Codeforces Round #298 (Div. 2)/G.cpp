#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t,maz[25][25],m,n,cnt;
void dfs(int x,int y){
    maz[x][y]=0;
    cnt++;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx,ny=y+dy;
            if(0<=nx&&nx<m&&0<=ny&&ny<n&&maz[nx][ny]==1)dfs(nx,ny);
                }
    }
}
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&maz[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt=0;
                if(maz[i][j]==1)dfs(i,j);
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}