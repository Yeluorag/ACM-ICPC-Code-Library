#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100005;

int n,m,a[maxn],sum,ans;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
    	for(int i=0;i<n;i++) a[i]=i+1;
    	int cmd,l,r;
    	ans=0;
    	sum=(1+n)*n/2;
    	for(int i=0;i<m;i++){
    		scanf("%d",&cmd);
    		if(cmd<4)scanf("%d%d",&l,&r);
    	}
    }
    return 0;
}
