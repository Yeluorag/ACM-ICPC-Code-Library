#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int T,cas=0,ans;


int dfs()
{
    int w1,d1,w2,d2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(w1&&w2&&d1&&d2){
        if(w1*d1!=w2*d2) {ans=0; return 0;}
        else  return (w1+w2);
    }else{
        if(!w1)  w1=dfs();
        if(!w2)  w2=dfs();
        if(w1*d1!=w2*d2) {ans=0; return 0 ; }
        else    return (w1+w2);
    }
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(cas<T){
        if(cas++)puts("");
        ans=1;
        getchar();
        dfs();
        printf("%s\n",ans?"YES":"NO");
    }
    return 0;
}
