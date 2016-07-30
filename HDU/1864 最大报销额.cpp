#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,m,cnt,flag[35],f[35],dp[3000005];
char c;
double Q,a[35];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%lf%d",&Q,&N),N){
    	cnt=0;
    	memset(flag,0,sizeof(flag));
    	memset(a,0,sizeof(a));
    	for(int i=0;i<N;i++){
    		scanf("%d",&m);
    		for(int j=0;j<m;j++){
    			double temp;
    			scanf("%c:%lf",&c,&temp);
    			if(c!='A'&&c!='B'&&c!='C')flag[i]=1;
    			if(temp>600)flag[i]=1;
    			a[i]+=temp;
    			if(a[i]>1000)flag[i]=1;
    		}
    		if(!flag[i])f[cnt++]=(int)(a[i]*100);
    	}
    	for(int i=0;i<cnt;i++){
    		for(int j=(int)(Q*100);j>=f[i];j--){
    			dp[j]=max(dp[j],dp[j-f[i]]+f[i]);
    		}
    	}
    	double ans=dp[(int)(Q*100)]/100;
    	printf("%.2lf\n",ans);
    }
    return 0;
}
