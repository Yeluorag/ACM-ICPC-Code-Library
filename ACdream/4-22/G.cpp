#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int p,l,w,n,y[505];
double x[505],hs[30005];
struct sta
{
	double x;
	int y;
}st[505];
bool cmp(sta a,sta b){
	a.y<b.y;
}
int main(){
	while(scanf("%d%d%d%d",&p,&l,&w,&n)!=EOF){
		for(int i=0;i<n;i++){
			double t;int k;
			scanf("%lf%d",&t,&k);
			hs[k]=t;
			x[i]=t;
		}
		sort(y,y+n);
		double pn=x[0],ans=0;
		int pos=0,i=1,yl=0,now=0;
		while(pos<L){
			if(hs[x[i]]<=pn){
				if((x[i]-pos)/w>p-yl)y
			}
		}
	}
	return 0;
}