#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,a,b[205],dp[205][205];
vector<int>son[205];
void dfs(int idx,int M){
	int len=son[idx].size();
	dp[idx][1]=b[idx];
	for(int i=0;i<len;i++){
		if(M>1) dfs(son[idx][i],M-1);
		for(int j=M;j>=1;j--){
			for(int k=1;k<=j;k++){
				dp[idx][j+1]=max(dp[idx][j+1],dp[son[idx][i]][k]+dp[idx][j+1-k]);
			}
		}
	}
}

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n&&m){
    	memset(dp,0,sizeof(dp));
    	for(int i=0;i<205;i++)son[i].clear();
    	for(int i=1;i<=n;i++){
    		scanf("%d%d",&a,&b[i]);
    		son[a].push_back(i);
    	}
    	dfs(0,m+1);
    	printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
