#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=100005;

vector<int> son[MAX];
int n,T,t;
int dfs(int u){
	if(son[u].empty())return 1;
	int len=son[u].size();
	vector<int> dp;
	for(int i=0;i<len;i++) dp.push_back(dfs(son[u][i]));
	sort(dp.begin(),dp.end())
	int k=(len*T-1)/100+1,ans=0;
	for(int i=0;i<k;i++) ans+=dp[i];
	return ans;
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&T),n&&T){
    	for(int i=0;i<MAX;i++)son[i].clear();
    	for(int i=1;i<=n;i++){
    		scanf("%d",&t);
    		son[t].push_back(i);
    	}
    	int ans=dfs(0);
    	printf("%d\n",ans);
    }
    return 0;
}
