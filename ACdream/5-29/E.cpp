#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=45;
vector<int> pi;
vector<int>::iterator it;

int n,w,p[105],ans=-1,idx=0,n2;
void dfs2(int now,int cur){
    if(now<=w) pi.push_back(now);
    if(cur<n){
        dfs2(now,cur+1);
        dfs2(now+p[cur],cur+1);
    }
}

void dfs(int now,int cur){
    int w2=w-now;
    if(w2==0){ans=w;return;}
    else if(w2>0){
        it=upper_bound(pi.begin(),pi.end(),w2);
        it--;
        int temp=0,len=pi.size();
        if(len){
            if(pi[len-1]<w2)temp=pi[len-1];
            else temp=*it;
        }
        ans=max(ans,temp+now);
        if(cur<n2){
            dfs(now,cur+1);
            dfs(now+p[cur],cur+1);
        }
    }
}

int main(){
    //freopen("/Users/apple/input.txt","r",stdin);
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    sort(p,p+n);
    n2=n/2;
    dfs2(0,n/2);
    sort(pi.begin(),pi.end());
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}

