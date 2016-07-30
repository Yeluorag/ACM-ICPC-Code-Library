#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=100005;
#define rep(i,n) for(int i=0;i<(n);i++)
int n,x[MAX],h[MAX],dp[MAX],ans=2,pos;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    scanf("%d",&n);
    rep(i,n)scanf("%d%d",&x[i],&h[i]);
    pos=x[0];
    for(int i=1;i<n-1;i++){
    	if(x[i]-h[i]>pos){
    		pos=x[i];
    		ans++;
    	}
    	else if(x[i]+h[i]<x[i+1]){
    		pos=x[i]+h[i];
    		ans++;
    	}else pos=x[i];
    }
    if(n==1)ans=1;
    printf("%d\n",ans);
    return 0;
}

