#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a,b,res;

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
    	if(n-a>b+1) res=b+1;
    	else res=n-a;
    	printf("%d\n",res);
    }
    return 0;
}