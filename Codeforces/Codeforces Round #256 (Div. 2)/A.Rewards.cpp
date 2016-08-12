#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a1,a2,a3,b1,b2,b3,n,a,b;
    scanf("%d%d%d",&a1,&a2,&a3);
    scanf("%d%d%d",&b1,&b2,&b3);
    cin>>n;
    a=a1+a2+a3;
    b=b1+b2+b3;
    n=n-a/5-b/10;
    if(a%5>0)n--;
    if(b%10>0)n--;
    if(n>=0)printf("YES\n");
    else printf("NO\n");
}
