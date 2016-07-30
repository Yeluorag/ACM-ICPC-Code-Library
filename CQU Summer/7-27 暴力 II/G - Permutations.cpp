#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;

int n,k,r[10],ans,mi,mx;
char a[10][10],b[10][10];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&k)!=EOF) {
        for(int i=0;i<n;i++) scanf("%s",a[i]);
        for(int i=0;i<k;i++) r[i]=i;
        ans=inf;
        do{
            mi=inf;mx=-inf;
            for(int i=0;i<n;i++){
                int res=0;
                for(int j=0;j<k;j++){
                    b[i][j]=a[i][r[j]];
                    res=res*10+b[i][j]-'0';
                }
                
                mx=max(mx,res);
                mi=min(mi,res);
            }
            ans=min(ans,mx-mi);
        }while(next_permutation(r,r+k));
        printf("%d\n",ans);
    }
    return 0;
}