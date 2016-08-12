#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,g[1005],f[1005];
bool cmp(int a,int b){ return a>b;}
int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	while(scanf("%d%d",&n,&k)!=EOF){
		bool ans=true;
		for(int i=0;i<n;i++)scanf("%d",&g[i]);
		for(int i=0;i<n;i++)scanf("%d",&f[i]);
		sort(g,g+n);
		sort(f,f+n,cmp);
		for(int i=0;i<n;i++){
			if(g[i]+f[i]<k){
				ans=false;break;
			}
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}