#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[7],ans=0,n=0;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    for(int i=0;i<6;i++) {
    	scanf("%d",&d[i]);
    	n+=d[i];
    }
    n/=3;
    int a,b,c;
   	if(d[0]<d[3]){
   		a=d[1],b=d[3];c=d[5];
   	}else {
   		a=d[0];b=d[2];c=d[4];
   	}
	ans=n*n;
	int n1=(n+a-b-c)/2,n2=(n+b-a-c)/2,n3=(n+c-a-b)/2;
	ans=n*n-n1*n1-n2*n2-n3*n3;
	printf("%d\n",ans);
    return 0;
}
