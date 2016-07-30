#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX=105;
int n,kase=0;
double x[MAX*2];

struct node{
	double x,y,w,d,h;
	int id;
	bool operator < (const node& t) const {
		return x<t.x||(x==t.x&&y<t.y);
	}
}b[MAX];

bool cover(int i,double mx){return b[i].x=mx&&b[i].x+b[i].w>=mx;}

bool visible(int i,double mx){
    if(!cover(i,mx)) return false;
    for(int k=0;k<n;k++)
        if(b[k].y<b[i].y&&b[k].h>=b[i].h&&cover(k,mx))return false;
    return true;
}


int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    while(scanf("%d",&n),n){
    	for(int i=0;i<n;i++){
    		scanf("%lf%lf%lf%lf%lf",&b[i].x,&b[i].y,&b[i].w,&b[i].d,&b[i].h);
    		b[i].id=i+1;
    		x[i*2]=b[i].x;x[i*2+1]=b[i].x+b[i].w;
    	}
        sort(b,b+n);
        sort(x,x+2*n);
        int m=unique(x,x+2*n)-x;
        if(kase++)puts("");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d",kase,b[0].id);
        for(int i=1;i<n;i++){
            bool vis=false;
            for(int j=0;j<m-1;j++)
                if(visible(i,(x[j]+x[j+1])/2)){vis=true;break;}
            if(vis)printf(" %d",b[i].id);
        }
        puts("");
    }
    return 0;
}
