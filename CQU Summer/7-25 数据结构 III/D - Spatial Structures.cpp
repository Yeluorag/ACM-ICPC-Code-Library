#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,cas=0;
char maz[70][70];
int flag[66][66][66][66],mtx[70][70];
vector<int> in;
vector<int> ans;

bool dfs(int nx,int ny,int sx,int sy){
    int mx=(nx+sx)/2,my=(ny+sy)/2;
//    if(nx>sx||ny>sy) return false;
    if(nx==sx&&ny==sy) {
//        printf("maz[%d][%d]: %d\n",nx,ny,maz[nx][ny]-'0');
        return flag[nx][ny][nx][ny]=maz[nx][ny]-'0';
    }
    bool nw=dfs(nx,ny,mx,my),
    ne=dfs(nx,my+1,mx,sy),
    sw=dfs(mx+1,ny,sx,my),
    se=dfs(mx+1,my+1,sx,sy);
//    printf("flag[%d][%d][%d][%d]: %d\n",nx,ny,sx,sy,(nw||ne||sw||se));
    return flag[nx][ny][sx][sy]=(nw||ne||sw||se);
}

void dfs2(int nx,int ny,int sx,int sy,int cnt,int now){
    if(!flag[nx][ny][sx][sy]) return;
//    if(nx>sx||ny>sy) return;
    int mx=(nx+sx)/2,my=(ny+sy)/2,nxt=cnt*5;
    bool nw=flag[nx][ny][mx][my],
    ne=flag[nx][my+1][mx][sy],
    sw=flag[mx+1][ny][sx][my],
    se=flag[mx+1][my+1][sx][sy];
    if(nx==sx&&ny==sy) nw=ne=sw=se=flag[nx][ny][sx][sy];
    if(nw&&ne&&sw&&se){
        ans.push_back(now);
    }
//    if(nx==sx&&ny==sy) return;
    if(nw) dfs2(nx,ny,mx,my,nxt,now+cnt);
    if(ne) dfs2(nx,my+1,mx,sy,nxt,now+2*cnt);
    if(sw) dfs2(mx+1,ny,sx,my,nxt,now+3*cnt);
    if(se) dfs2(mx+1,my+1,sx,sy,nxt,now+4*cnt);
}

void decode(){
    int len=in.size(),nx,ny,sx,sy;
    for(int i=0;i<len;i++){
        int temp=in[i];
        nx=1;ny=1;sx=n;sy=n;
        while(temp){
            int c=temp%5,mx=(nx+sx)/2,my=(ny+sy)/2;
            switch (c) {
                case 1:sx=mx;sy=my;break;
                case 2:ny=my+1;sx=mx;break;
                case 3:nx=mx+1;sy=my;break;
                case 4:nx=mx+1;ny=my+1;break;
                default:break;
            }
            temp/=5;
        }
        for(int i=nx;i<=sx;i++) for(int j=ny;j<=sy;j++) mtx[i][j]=1;
    }
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        memset(flag,0,sizeof(flag));
        if(cas++) puts("");
        printf("Image %d\n",cas);
        if(n>0){
            ans.clear();
            for(int i=1;i<=n;i++) scanf("%s",maz[i]+1);
            bool res=dfs(1,1,n,n);
            dfs2(1,1,n,n,1,0);
            sort(ans.begin(),ans.end());
            int len=ans.size();
            for(int i=0;i<len-1;i++) printf("%d ",ans[i]);
            if(len) printf("%d\n",ans[len-1]);
            printf("Total number of black nodes = %d\n",len);
        }else{
            n=-n;
            memset(mtx,0,sizeof(mtx));
            in.clear();
            int x;
            while(scanf("%d",&x)&&x!=-1) in.push_back(x);
            decode();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) printf("%c",mtx[i][j]?'*':'.');
                puts("");
            }
        }
    }
    return 0;
}