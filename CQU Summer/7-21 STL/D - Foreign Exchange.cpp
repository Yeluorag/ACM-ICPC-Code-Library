#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=500005;
int n,ans;
int st1[maxn],st2[maxn];
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
    	ans=1;
    	for(int i=0;i<n;i++) 
    		scanf("%d%d",&st1[i],&st2[i]);
    	sort(st1,st1+n);
    	sort(st2,st2+n);
    	for(int i=0;i<n;i++) {
    		if(st1[i]!=st2[i]){
    			ans=0;break;
    		}
    	}
    	printf("%s\n",ans?"YES":"NO");
    }
    return 0;
}
