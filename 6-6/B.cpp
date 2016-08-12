#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX=100005;
const ll INF = 1e15;

int T,n,w=0;
ll m;

struct edge{
    ll v,r,t;
}a[MAX];
struct node
{
    ll v,t;
    friend bool operator<(node p,node q){
        return p.t>q.t;
    }
};
bool cmp(edge p,edge q){ return p.r<q.r; }

ll bfs(){
    node t1,t2;
    ll i,l=0;
    t1.v=1;t1.t=0;
    priority_queue<node> que;
    que.push(t1);
    while(!que.empty()){
        t2=que.top();que.pop();
        if(t2.v>=m)return t2.t;
        for(i=l;i<n;i++){
            if(t2.v>=a[i].r&&a[i].v>t2.v){
                t1.v=a[i].v;
                t1.t=t2.t+a[i].t;
                que.push(t1);
            }
            if(t2.v<a[i].r)break;
        }
        l=i;
    }
    return -1;
}
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","r",stdin);
    cin>>T;
    while(w<T){
       	scanf("%d%lld",&n,&m);
        for(int i=0;i<n;i++)scanf("%lld%lld%lld",&a[i].v,&a[i].r,&a[i].t);
        sort(a,a+n,cmp);
        ll ans=bfs();
        printf("Case #%d: %lld\n",++w,ans);
    }
    return 0;
}
