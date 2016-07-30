#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
const unsighed long long MOD=1<<64;
int T,n,w=0,ans;
int num[15],a[15],f[15];
char pk[60][5];
void dfs(int last,int cnt){
	if(cnt==n)ans++;
	for(int i=0;i<n;i++){
		if(!f[a[i]]&&a[i]!=last){
			f[a[i]]=1;
			dfs(a[i],cnt+1);
			f[a[i]]=0
		}
	}
}
map<char,int> mp;
int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	mp['T']=10;mp['J']=11;mp['Q']=12;mp['K']=13;mp['A']=1;
	cin>>T;
	while(w<T){
		ans=0;
		memset(num,0,sizeof(num));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		int mul=1,idx=0;
		for(int i=0;i<n;i++){
			scanf("%s",pk[i]);
			if(pk[i][0]>'1'&&pk[i][0]<'10')num[pk[i][0]-'0']++;
			else num[mp[pk[i][0]]]++;
			a[idx++]=mp[pk[i][0]];
		}
		dfs(-1,0);
		printf("Case #%d: %d\n",++w,ans);
	}
	return 0;
}