#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200005;
int a[maxn],cas=0,ul=maxn,ur=-1;

void dfs(int now){
	int l,r;
	scanf("%d%d",&l,&r);
	if(l!=-1){
		dfs(now-1);
		a[now-1]+=l;
		ul=min(ul,now-1);
	}
	if(r!=-1){
		dfs(now+1);
		a[now+1]+=r;
		ur=max(ur,now+1);
	}
}
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    int root;
    while(scanf("%d",&root)&&root!=-1){
    	if(cas) puts("");
    	memset(a,0,sizeof(a));
    	ul=maxn,ur=-1;
    	dfs(maxn/2);
    	printf("Case %d:\n",++cas);
    	for(int i=ul;i<ur;i++) if(a[i]>0) printf("%d ",a[i]);
    	if(a[ur])printf("%d",a[ur]);
    	puts("");
    }
    return 0;
}
