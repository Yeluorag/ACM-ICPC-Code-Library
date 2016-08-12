#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;


double a[5];
int T,f[5],cnt=0,ans;
void dfs(double now,int cur){
    if(cur==3){
        if (now-24<1e-6&&24-now<1e-6){
            ans=1;
            return;
        }
    }
    for (int i=0; i<4; i++) {
        if (!f[i]) {
            f[i]=1;
            dfs(now+a[i], cur+1);
            dfs(now-a[i], cur+1);
            dfs(a[i]-now, cur+1);
            dfs(now*a[i], cur+1);
            if(a[i]!=0)dfs(now/a[i], cur+1);
            if (now!=0)dfs(a[i]/now, cur+1);
            f[i]=0;
        }
    }

}
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    cin>>T;
    while(T--){
        cnt=0;
        scanf("%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3]);
        memset(f,0,sizeof(f));
        ans=0;
        for(int i=0;i<4;i++){
            f[i]=1;
            dfs(a[i],0);
            f[i]=0;
        }
        //        printf("-----%d\n",cnt);
        printf("%s\n",ans==1?"yes":"no");
    }
    return 0;
}