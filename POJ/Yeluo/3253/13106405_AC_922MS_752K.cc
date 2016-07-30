#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
int N,L[20001];
ll ans=0;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&L[i]);
    while(N>1){
        int m1=0,m2=1;
        if(L[m1]>L[m2])swap(m1,m2);
        for(int i=2;i<N;i++){
            if(L[i]<L[m1]){
                m2=m1;
                m1=i;
            }
            else if(L[i]<L[m2])
                m2=i;
        }
        ans+=L[m1]+L[m2];
        if(m1==N-1)swap(m1,m2);
        L[m1]=L[m1]+L[m2];
        L[m2]=L[N-1];
        N--;
    }
    printf("%lld\n",ans);
    return 0;
}
