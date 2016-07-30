#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=500005;
int n,par[MAX],flag[MAX],bh[MAX];
int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		int cnt=0;
		memset(flag,0,sizeof(flag));
		for(int i=2;i<=n;i++)scanf("%d",&par[i]);
		for(int i=n;i>=2;i--){
			if(flag[i]==0&&flag[par[i]]==0){
				flag[i]=1;flag[par[i]]=1;bh[cnt++]=i;
			}
		}
		printf("%d\n",cnt*1000);
		for(int i=cnt-1;i>0;i--)printf("%d ",bh[i]);
		cout<<bh[0]<<endl;
	}
	return 0;
}