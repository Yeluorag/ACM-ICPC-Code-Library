#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF=1000000000;
int n,m,x[100005];
bool C(int d){
    int num=1,flag=0;
    for(int i=1;i<n;i++){
        if(x[i]>=x[flag]+d){
            num++;
            flag=i;
        }
		if(num==m)return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    sort(x,x+n);
    int lb=0,ub=x[n-1]-x[0];
    while(lb<ub-1){
        int mid=(lb+ub)/2;
        if(C(mid))lb=mid;
        else ub=mid;
    }
    printf("%d\n",lb);
    return 0;
}
