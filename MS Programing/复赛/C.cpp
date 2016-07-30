#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX=100005;
int n,m,q,T,w=0,f[MAX],a[105][105];

int main(){
	//freopen("/Users/apple/input.txt","r",stdin);
	cin>>T;
	while(w<T){
		memset(f,-1,sizeof(f));
		memset(a,0,sizeof(a));
		int x,y,z,xw,ans=0;
		scanf("%d%d%d",&n,&m,&q);
		for(int i = 0; i < n; ++i)scanf("%d",&f[i+1]);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			a[x][y]=a[y][x]=z;
			if(f[x]!=f[y])ans+=z;
		}
		printf("Case #%d:\n",++w);
		for(int i=0;i<q;i++){
			scanf("%d",&xw);
			if(xw==3)printf("%d\n",ans);
			else if(xw==2){
				scanf("%d%d%d",&x,&y,&z);
				if(f[x]!=f[y])ans=ans-a[x][y]+z;
				a[x][y]=a[y][x]=z;
			}else if(xw==1){
				scanf("%d",&x);
				f[x]=(f[x]-1)*(-1);
				for(int i=1;i<=105;i++){
					if(x!=i&&a[x][i]>0){
						if(f[x]==f[i])ans-=a[x][i];
						else ans+=a[x][i];
					}
				}
			}
		}	
	}
	return 0;
}