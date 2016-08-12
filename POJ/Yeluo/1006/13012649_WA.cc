#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int p,e,i,d,m,w=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)&&p!=-1&&e!=-1&&i!=-1&&d!=-1){
        for(m=i;m<=100000;m+=33)
            if(((m-p)%23==0)&&((m-e)%28==0)&&m!=0)break;
		m-=d;
		if(m>21252) m%=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",w++,m);
    }
    return 0;
}
