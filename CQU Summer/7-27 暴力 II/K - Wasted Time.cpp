#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k;
double ans,x[105],y[105];
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&k)!=EOF){
    	ans=0;
    	for(int i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
    	for(int i=0;i<n;i++){
    		if(i) ans+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
    	}
    	ans=ans*k/50.0;
    	printf("%.9lf\n",ans);
    }
    return 0;
}