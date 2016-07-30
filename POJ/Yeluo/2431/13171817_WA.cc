#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int A[10005],B[10005],L,P,N;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d",&A[i],&B[i]);
    scanf("%d%d",&L,&P);
    A[N]=L;
    B[N]=0;
    N++;
    int tank=P,ans=0,pos=0;
    priority_queue<int>que;
    for(int i=0;i<N;i++){
        int d=A[i]-pos;
        while(tank<d&&!que.empty()){
            tank+=que.top();
            que.pop();
            ans++;
        }
        pos=A[i];
        tank-=d;
        if(tank<0){
            ans=-1;
            break;
        }
        que.push(B[i]);
    }
    printf("%d\n",ans);
    return 0;
}
