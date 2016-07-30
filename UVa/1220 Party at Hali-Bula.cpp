#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> son[205];
map<string,int> mp;
int n,dp[205][2],f[205][2];
void dfs(int u){
    dp[u][0]=0;
    dp[u][1]=1;
    f[u][0]=f[u][1]=1;
    int len=son[u].size();
    for(int i=0;i<len;i++){
        int t=son[u][i];
        dfs(t);
        if(dp[t][0]==dp[t][1]){
            dp[u][0]+=dp[t][0];
            f[u][0]=0;
        } else {
            int idx=dp[t][0]>dp[t][1]?0:1;
            dp[u][0]+=dp[t][idx];
            if(f[t][idx]==0)f[u][0]=0;
        }
        dp[u][1]+=dp[t][0];
        if(!f[t][0])f[u][1]=0;
    }
}
int main(){
     // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        memset(dp,0,sizeof(dp));
        memset(f,-1,sizeof(f));
        mp.clear();
        for(int i=0;i<205;i++)son[i].clear();
        string s1,s2;
        int idx=1;
        cin>>s1; mp[s1]=idx++;
        for(int i=0;i<n-1;i++){
            cin>>s1>>s2;
            if(!mp[s1])mp[s1]=idx++;
            if(!mp[s2])mp[s2]=idx++;
            int a=mp[s1],b=mp[s2];
            son[b].push_back(a);
        }
        dfs(1);
        if(dp[1][0]==dp[1][1])f[1][0]=f[1][1]=0;
        idx=dp[1][0]>dp[1][1]?0:1;
        printf("%d %s\n",dp[1][idx],f[1][idx]?"Yes":"No");
    }
    return 0;
}
