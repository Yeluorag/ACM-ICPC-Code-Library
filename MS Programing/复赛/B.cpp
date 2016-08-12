#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int T,n,m,k,w=0,w[1005],g[1005][1005],c[1000005];
vector<int> d[1005];
int dj[1005];
struct node
{
	int x,y,v;
};
vector<node>e;
int main(){
	cin>>T;
	while(w<T){
		int x,y,ans=0;
		memset(c,0,sizeof(c));
		memset(dj,0,sizeof(dj));
		memset(w,0,sizeof(d));
		memset(g,0,sizeof(g));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&w[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=w[x]+w[y];
			d[x].push_back(y);
			d[y].push_back(x);
			dj[x]+=w[y];
			dj[y]+=w[x]; 
			node t;
			t.x=x;t.y=y.t.v=w[x]+w[y];
			e.push_back(t);
		}
		int l=e.size();
		for(int i=0;i<l;i++){
			int p=e[i].x,q=e[i].y;
			if(dj[p]-e[i].v==0)c[i]+=w[p];
			if(dj[q]-e[i].v==0)c[i]+=w[q];
		}
		while(k){
			int mx=-1,idx=-1;
			for(int i=0;i<l;i++){
				if(c[i]=>mx){
					mx=c[i];
					idx=i;
				}
			}
			c[i]=0;
			g[e[i].x][e[i].y]=g[e[i].y][e[i].x]=0;
			dj[e[i].x]-=w[e[i].y];
			dj[e[i].y]-=w[e[i].x];
			k--;
		}
		for(int i=1;i<=n;i++){
			int t=0;
			for(int j=0;j<d[i].size();j++){
				
			}
		}

	}
	return 0;
}