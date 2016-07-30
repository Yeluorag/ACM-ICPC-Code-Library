#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,S,a[100005],sum[100005];
const int INF=10000000;

int C(int lb,int ub){
    int mid=(lb+ub)/2,cnt=sum[lb],s=lb;
    while(true){
        if(sum[mid]-cnt<S){
			lb=mid;
            mid=(mid+ub)/2;
		}
        else{
			ub=mid;
            mid=(mid+lb)/2;
		}
        if(sum[mid]-cnt<S&&sum[mid+1]-cnt>=S)
            return mid+1-s;
    }
}
int main()
{
    int T,res;
    scanf("%d",&T);
    while(T--){
		res=INF;
        scanf("%d%d",&n,&S);
        sum[0]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum[i+1]=sum[i]+a[i];
        }
        if(sum[n]<S){
            printf("0\n");
            continue;
        }
        for(int s=0;sum[n]-sum[s]>=S;s++){
            int t=C(s,n);
            res=min(res,t);
        }
        printf("%d\n",res);
    }
    return 0;
}
