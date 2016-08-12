#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int N,Q,n;
const int MAX_N=100005;
const int DAT_SIZE=(1<<18)-1;
int L[MAX_N],R[MAX_N],X[MAX_N],A[MAX_N];
char T[MAX_N];
ll data[DAT_SIZE],datb[DAT_SIZE];
void init(int n_)
{
    n=1;
    while(n<=n_)n*=2;
    for(int i=0;i<2*n-1;i++){
        data[i]=0;
        datb[i]=0;
    }
}
void add(int a,int b,int x,int k,int l,int r)
{
    if(a<=l&&r<=b) data[k]+=x;
    else if(l<b&&r>a){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
    }
}

ll sum(int a,int b,int k,int l,int r)
{
    if(b<=l||a>=r) return 0;
    else if(a<=l&&r<=b) return data[k]*(r-l)+datb[k];
    else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,2*k+1,l,(l+r)/2);
        res+=sum(a,b,2*k+2,(l+r)/2,r);
        return res;
    }
}
int main()
{
	char c;
    scanf("%d%d",&N,&Q);
    init(N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        add(i,i+1,A[i],0,0,N);
    }
    for(int i=0;i<Q;i++){
		scanf("%c",&c);
		scanf("%c%d%d",&T[i],&L[i],&R[i]);
        if(T[i]=='C'){
            scanf("%d",&X[i]);
            add(L[i]-1,R[i],X[i],0,0,N);
        }
        else printf("%I64d\n",sum(L[i]-1,R[i],0,0,N));
    }
    return 0;
}
