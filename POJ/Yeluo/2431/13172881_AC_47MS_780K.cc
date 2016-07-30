#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int L,P,N,t;
struct s{
	int dist,fuel;
}a[10010];
int cmp(const s &a,const s &b){
	return a.dist>b.dist;
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
		scanf("%d%d",&a[i].dist,&a[i].fuel);
	}
    scanf("%d%d",&L,&P);
    sort(a,a+N,cmp);
	a[N].dist=0;
	a[N].fuel=P;
    int tank=P,ans=0,pos=0;
    priority_queue<int>que;
    for(int i=0;i<=N;i++){
		int d=L-a[i].dist-pos;
        while(tank<d&&!que.empty()){
            tank+=que.top();
            que.pop();
            ans++;
        }
		pos=L-a[i].dist;
        tank-=d;
        if(tank<0){
            ans=-1;
            break;
        }
		que.push(a[i].fuel);
    }
    printf("%d\n",ans);
    return 0;
}
