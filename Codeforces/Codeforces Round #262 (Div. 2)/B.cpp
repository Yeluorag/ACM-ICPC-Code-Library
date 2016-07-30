#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define For(i,n) for(int i=0;i<n;i++)
ll a,b,c,x,cnt,ans[100000];
ll m(int x,int a){
    ll res=1;
    while(a--){
        res*=x;
    }
    return res;
}
int cal(ll x){
    int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    cnt=0;
    for(int i=0;i<=81;i++){
        ll t=(ll)b*m(i,a)+c;
		int k=cal(t);
        if(k==i&&t>0&&t<1000000000)ans[cnt++]=t;
    }
    printf("%d\n",cnt);
	if(cnt>0){
      For(i,cnt-1)printf("%d ",ans[i]);
      printf("%d\n",ans[cnt-1]);
	}
    return 0;
}
