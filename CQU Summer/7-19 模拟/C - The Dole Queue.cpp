#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,m,f[25];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        if(n==0&&k==0&&m==0) break;
        memset(f,0,sizeof(f));
        int cnt=n,l=1,r=n;
        while(cnt){
            int c=0;
            for(int i=l;c<k;i++){
                if(!i)continue;
                if(i>n)i-=n;
                if(!f[i]){
                    c++;
                    l=i;
                }
            }c=0;
            for(int i=r;c<m;i--){
                if(!i)continue;
                if(i<0) i+=n+1;
                if(!f[i]){
                    c++;
                    r=i;
                }
            }
            f[l]=1;f[r]=1;
            if(l==r) {printf("%3d",l);cnt--;}
            else {printf("%3d%3d",l,r);cnt-=2;}
            printf("%c",cnt?',':'\n');
        }
    }
    return 0;
}
