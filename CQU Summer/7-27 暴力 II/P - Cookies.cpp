#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int even,odd,t,sum,n;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
    	even=0;odd=0;sum=0;
    	for(int i=0;i<n;i++){
    		scanf("%d",&t);
    		if(t%2) odd++;
    		else even++;
    		sum+=t;
    	}
    	printf("%d\n",sum%2?odd:even);

    }
    return 0;
}