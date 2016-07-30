#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,a[105],vis[105],prm[105];
void dfs(int cur){
    if(cur==n&&prm[a[0]+a[n-1]]){
        for(int i=0;i<n-1;i++)printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]&&prm[a[cur-1]+i]){
            a[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main(){
    //freopen("/Users/apple/input.txt","r",stdin);
    for(int i=2;i<40;i++){
        int f=1;
        for(int j=2;j*j<=i;j++)if(i%j==0)f=0;
        if(f)prm[i]=1;
    }a[0]=1;int w=0;
    while(scanf("%d",&n)!=EOF){
        memset(vis, 0, sizeof(vis));
        if(w)puts("");
        printf("Case %d:\n",++w);
        dfs(1);
    }
    return 0;
}
