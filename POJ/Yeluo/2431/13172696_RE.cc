#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int A[50005],B[50005],L,P,N,t;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
		scanf("%d%d",&A[i],&t);
		B[A[i]]=t;
	}
    scanf("%d%d",&L,&P);
    sort(A,A+N);
    reverse(A,A+N);
    A[N]=0;
    B[0]=0;
    int tank=P,ans=0,pos=0;
    priority_queue<int>que;
    for(int i=0;i<=N;i++){
        int d=L-A[i]-pos;
        while(tank<d&&!que.empty()){
            tank+=que.top();
            que.pop();
            ans++;
        }
        pos=L-A[i];
        tank-=d;
        if(tank<0){
            ans=-1;
            break;
        }
        que.push(B[A[i]]);
    }
    printf("%d\n",ans);
    return 0;
}
