#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,S,a[100005];
const int INF=10000000;

int main()
{
    int T,res;
    scanf("%d",&T);
    while(T--){
		res=INF;
        scanf("%d%d",&n,&S);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int s=0,t=0,sum=0;
        while(true){
			while(t<n&&sum<S){
				sum+=a[t++];
			}
			if(sum<S)break;
			res=min(res,t-s);
			sum-=a[s++];
		}
		if(res>n) res=0;
        printf("%d\n",res);
    }
    return 0;
}
