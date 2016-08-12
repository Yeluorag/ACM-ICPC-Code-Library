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
    priority_queue<int>pque;
    int pos=0,tank=P,ans=0;
    for(int i=0;i<=N;i++){
        int d=A[i]-pos;
        while(tank<d){
            if(pque.empty()){
                printf("-1\n");
                return 0;
            }
            tank+=pque.top();
            pque.pop();
            ans++;
        }
        tank-=d;
        pos=A[i];
        pque.push(B[i]);
    }
    printf("%d\n",ans);
    return 0;
}
