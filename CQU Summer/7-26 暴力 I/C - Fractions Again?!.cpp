#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&k)!=EOF){
    	printf("%d\n",k);
    	for(int x=1;x<=2*k;x++){
    		int y=-1;
    		if((x*k%(x-k))==0){
    			y=x*k/(x-k);
    			int a=max(x,y),b=min(x,y);
    			printf("1/%d = 1/%d + 1/%d\n",k,a,b);
    		}
    	}
    }
    return 0;
}