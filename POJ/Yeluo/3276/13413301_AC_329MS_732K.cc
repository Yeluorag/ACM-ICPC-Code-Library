#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N=5005;
const int INF=2000000000;

int n,f[MAX_N],dir[MAX_N];
char c;

int cal(int k){
    memset(f,0,sizeof(f));
    int res=0,sum=0;
    for(int i=0;i+k<=n;i++){
        if((dir[i]+sum)%2==0){
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-k+1>=0) sum-=f[i-k+1];

    }
    for(int i=n-k+1;i<n;i++){
        if((dir[i]+sum)%2==0) return INF;
        if(i-k+1>=0)sum-=f[i-k+1];
    }
    return res;
}
int main()
{
    int cnt=0,k=0,ans=INF,anst;
    scanf("%d",&n);
    for(int i=0;i<n;){
        scanf("%c",&c);
		if(c=='B'){dir[i]=0;i++;}
		if(c=='F'){dir[i]=1;i++;}
    }
    for(int i=1;i<=n;i++){
        anst=cal(i);
        if(anst<ans){
            k=i;
            ans=anst;
        }
    }
    printf("%d %d\n",k,ans);
    return 0;
}
