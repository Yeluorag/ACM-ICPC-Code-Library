#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,t,cnt[105];
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
    	memset(cnt,0,sizeof(cnt));
    	for(int i=0;i<n;i++) {
    		scanf("%d",&t);
    		cnt[t]++;
    	}
    	int res=0;
    	for(int i=1;i<=100;i++) {
    		cnt[i]/=2;
    		res+=cnt[i];
    	}
    	printf("%d\n",res/2);
    }
    return 0;
}