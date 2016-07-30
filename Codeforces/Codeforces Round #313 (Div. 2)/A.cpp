#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1005],ans=-1;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    int n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
	if(a[0]>1)ans=1;
	printf("%d\n",ans);
    return 0;
}
