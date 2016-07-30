#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a1,b1,a2,b2,a3,b3;
int ans=0;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    scanf("%d%d",&a1,&b1);
    scanf("%d%d",&a2,&b2);
    scanf("%d%d",&a3,&b3);
    if(a2+a3<=a1&&b2<=b1&&b3<=b1) ans=1;
    if(a2+b3<=a1&&b2<=b1&&a3<=b1) ans=1;
    if(b2+b3<=a1&&a2<=b1&&a3<=b1) ans=1;
    if(b2+a3<=a1&&a2<=b1&&b3<=b1) ans=1;
    if(a2+a3<=b1&&b2<=a1&&b3<=a1) ans=1;
    if(a2+b3<=b1&&b2<=a1&&a3<=a1) ans=1;
    if(b2+b3<=b1&&a2<=a1&&a3<=a1) ans=1;
    if(b2+a3<=b1&&a2<=a1&&b3<=a1) ans=1;
    printf("%s\n",ans?"YES":"NO");
    return 0;
}
