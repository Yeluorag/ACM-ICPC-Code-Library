#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1005;

int n,vis[maxn];
double sy,gy;

struct Circle{
    int x,y,r;
    void input(){
        scanf("%d%d%d",&x,&y,&r);
    }
}c[maxn];

bool check(Circle a,Circle b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)-(a.r+b.r)*(a.r+b.r)<=0;
}

bool dfs(int u){
    vis[u]=1;
    if(c[u].y-c[u].r<=0) return false;
    if(c[u].x-c[u].r<=0) sy=min(sy,c[u].y-sqrt(c[u].r*c[u].r-c[u].x*c[u].x));
    if(1000-c[u].x-c[u].r<=0) gy=min(gy,c[u].y-sqrt(c[u].r*c[u].r-(1000-c[u].x)*(1000-c[u].x)));
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(check(c[u],c[i])){
            if(!dfs(i)) return false;
        }
    }
    return true;
}

void solve(){
    sy=gy=1000;
    for(int i=0;i<n;i++){
        if(!vis[i]&&c[i].y+c[i].r>=1000){
            if(!dfs(i)){
                printf("IMPOSSIBLE\n");
                return;
            }
        }
    }
    printf("0.00 %.2lf 1000.00 %.2lf\n",sy,gy);
}


int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //    freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)==1){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) c[i].input();
        solve();
    }
    return 0;
}