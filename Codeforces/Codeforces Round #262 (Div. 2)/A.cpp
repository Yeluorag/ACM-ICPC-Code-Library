#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
int main()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    while(true){
        if(n>=m)ans+=m;
        else ans+=n;
        n-=m;
        n++;
        if(n<=0)break;
    }
    printf("%d\n",ans);
    return 0;
}
