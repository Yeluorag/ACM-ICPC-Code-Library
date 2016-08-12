#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,w=0;
double v;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","r",stdin);
    cin>>T;
    while(w<T){
    	scanf("%lf",&v);
    	printf("Case #%d: ",++w);
    	if(v>=1.000) printf("Too Bright\n");
    	else if(v<1.000&&v>=0.400) printf("1\n");
    	else if(v<0.400&&v>=0.160) printf("2\n");
    	else if(v<0.160&&v>=0.063) printf("3\n");
    	else if(v<0.063&&v>=0.025) printf("4\n");
    	else if(v<0.025&&v>=0.010) printf("5\n");
    	else if(v<0.010&&v>=0.004) printf("6\n");
    	else printf("Invisible\n");
    }
    return 0;
}
