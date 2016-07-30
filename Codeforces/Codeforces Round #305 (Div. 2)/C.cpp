#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXM=100005;

int n,x1,x2,y1,y2,a1,a2,h1,h2,ans;
int b[2][MAXM],hs[2][MAXM],c1=-1,c2=-1;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    memset(hs1,-1,sizeof(hs1));

    scanf("%d",&m);
    scanf("%d%d%d%d%d%d%d%d",&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    int t=h1,idx=0;
    hs[0][t]=idx;
    b[0][idx++]=t;
    for(int i=0;i<MAXM;i++){
    	t=(x1*t+y1)%m;
    	if(t==h1){c1=i;t=h2;idx=0;break;}
    	hs[0][t]=idx;
    	b[0][idx++]=t;
    }b[1][idx++]=t;hs[1][t]=0;
    for(int i=0;i<MAXM;i++){
    	t=(x1*t+y1)%m;
    	if(t==h2){c2=i;break;}
    	hs[1][t]=idx;
    	b[1][idx++]=t;
    }


    return 0;
}
