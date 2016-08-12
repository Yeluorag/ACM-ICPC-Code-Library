#include <iostream>
#include <cstdio>
using namespace std;
int mi(int x,int y){return x<y?x:y;}
int main()
{
    int n,m,t;
    while(scanf("%d%d",&n,&m)!=EOF){
       t=mi(m,n);
       printf("%s\n",t%2==1?"Akshat":"Malvika");
    }
    return 0;
}
