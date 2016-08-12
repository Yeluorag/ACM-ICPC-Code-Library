#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int f(int x,int y){
    return x>y?(x-y):(y-x);
}

int main()
{
    int x1,x2,y1,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1!=x2&&y1!=y2){
        if(f(x1,x2)!=f(y1,y2))printf("-1\n");
        else printf("%d %d %d %d",x1,y2,x2,y1);
    }else if(x1==x2){
        int t=f(y2,y1);
        printf("%d %d %d %d",x1+t,y1,x1+t,y2);
    }else if(y1==y2){
        int t=f(x1,x2);
        printf("%d %d %d %d",x1,y1+t,x2,y1+t);
    }
    return 0;
}

