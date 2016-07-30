#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int p,e,i,d,m,w=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)&&p!=-1&&e!=-1&&i!=-1&&d!=-1){
        int res;
        res=(5544*p+14421*e+1288*i+21252)%21252;
        if(res==0) res=21252;
        res-=d;
        printf("Case %d: the next triple peak occurs in %d days.\n",w++,res);
    }
    return 0;
}
