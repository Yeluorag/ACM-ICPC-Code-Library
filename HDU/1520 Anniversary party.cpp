#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> son[6005];
int n,l,k,root;
int v[6005],dp[6005][2],pare[6005];
void dfs(int idx){
	int len=son[idx].size();
	dp[idx][0]=0;
	dp[idx][1]=v[idx];
	for(int i=0;i<len;i++){
		int t=son[idx][i];
		dfs(t);
		dp[idx][0]+=max(dp[t][0],dp[t][1]);
		dp[idx][1]+=dp[t][0];
	}
}

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
    	root=0;
    	memset(dp,0,sizeof(dp));
    	memset(pare,-1,sizeof(pare));
    	for(int i=0;i<6005;i++)son[i].clear();
    	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    	while(scanf("%d%d",&l,&k)&&l+k){ son[k].push_back(l); pare[l]=k; }
    	for(int i=1;i<=n;i++){ if(pare[i]==-1) { root=i; break; } }
    	dfs(root);
    	printf("%d\n",max(dp[root][0],dp[root][1]));
    }
    return 0;
}
