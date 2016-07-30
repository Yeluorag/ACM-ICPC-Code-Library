#include <iostream>
#include <cstdio>
#include <cstring>

int T,n,m;
using namespace std;

int main()
{
//    freopen("/Users/apple/input.txt","r",stdin);
    // freopen("/Users/apple/out.txt","w",stdout);
    while (scanf("%d",&T)!=EOF){
        if(T==-1)break;
        while (T--) {
            scanf("%d%d",&m,&n);
            int k = 1;
            while (--m) {
                if (n%2) k = k<<1;
                else k = (k<<1)+1;
                n = (n+1)>>1;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
