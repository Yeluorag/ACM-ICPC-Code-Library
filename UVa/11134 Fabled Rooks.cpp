#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i< (n);i++)
const int MAX=5005;
int n;
struct node{
	int l,r,id;
    friend bool operator<(const node &a,const node &b){
        if(a.l==b.l)return a.r>b.r;
        return a.l>b.l;
    }
};
int ans[MAX][2];
bool solve(node *ar,int idx){
    priority_queue<node> que;
    rep(i,n) que.push(ar[i]);
    int maxx=0;
    while(!que.empty()){
        node t=que.top();que.pop();
        if(t.r<maxx) return false;
        if(t.l<maxx){
            t.l=maxx;
            que.push(t);
            continue;
        }
        int cur=max(maxx,t.l);
        ans[t.id][idx]=cur;
        maxx=cur+1;
    }
    return true;
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    while(scanf("%d",&n),n){
    	node ar1[MAX],ar2[MAX];
    	rep(i,n){
    		scanf("%d%d%d%d",&ar1[i].l,&ar2[i].l,&ar1[i].r,&ar2[i].r);
            ar1[i].id=ar2[i].id=i;		
    	}
    	if(solve(ar1,0)&&solve(ar2,1))rep(i,n)printf("%d %d\n",ans[i][0],ans[i][1]);
    	else printf("IMPOSSIBLE\n");
    }
    return 0;
}
