#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
int N,L[20005];
int main()
{
    priority_queue<int,vector<int>,greater<int> >que;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&L[i]);
        que.push(L[i]);
    }
    ll ans=0;
    while(que.size()>1){
        int a,b;
        a=que.top();
        que.pop();
        b=que.top();
        que.pop();
        ans+=a+b;
        que.push(a+b);
    }
    printf("%I64d\n",ans);
    return 0;
}