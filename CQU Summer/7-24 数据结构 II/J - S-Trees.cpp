#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,tmn[130],a[9],ans[20005],cas=0;
char x;
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        cas++;
        for(int i=0;i<n;i++){
            getchar();
            scanf("%c%d",&x,&m);
        }
        for(int i=1;i<=pow(2,n);i++)
            scanf("%1d",&tmn[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int idx=1;
            for(int j=1;j<=n;j++){
                scanf("%1d",&a[j]);
                if(a[j])idx+=pow(2,n-j);
            }
            ans[i]=tmn[idx];
        }
        printf("S-Tree #%d:\n",cas);
        for(int i=1;i<=m;i++) printf("%d",ans[i]);
        puts("\n");
    }
    return 0;
}