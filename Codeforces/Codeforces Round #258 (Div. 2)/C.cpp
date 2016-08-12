#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,k;
ll max(ll x,ll y,ll z){
    ll t=x>y?x:y;
    return t>z?t:z;
}
ll min(ll x,ll y,ll z){
    ll t=x<y?x:y;
    return t<z?t:z;
}
ll mid(ll x,ll y,ll z){
  return x+y+z-max(x,y,z)-min(x,y,z);
}
bool pd(ll x,ll y,ll z){
	if(x<0||y<0||z<0)return false;
    ll m[3]={max(x/3,y/3,z/3),mid(x/3,y/3,z/3),min(x/3,y/3,z/3)};
    ll cnt=n-k;
    cnt=cnt-2*m[0]+m[1]+m[2];
    if(cnt<0) return false;
    else if(cnt==0)return true;
    else {
        if(cnt%3==0)return true;
        else return false;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        ll d1,d2;
        bool flag=false;
        scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
        if(!flag&&(k+2*d1-d2)%3==0&&(k-d1-d2)%3==0&&(k-d1+2*d2)%3==0){
            flag=pd(k+2*d1-d2,k-d1-d2,k-d1+2*d2);
        }
        if(!flag&&(k+2*d1+d2)%3==0&&(k-d1+d2)%3==0&&(k-d1-2*d2)%3==0){
            flag=pd(k+2*d1+d2,k-d1+d2,k-d1-2*d2);
        }
        if(!flag&&(k-2*d1+d2)%3==0&&(k+d1+d2)%3==0&&(k+d1-2*d2)%3==0){
            flag=pd(k-2*d1+d2,k+d1+d2,k+d1-2*d2);
        }
        if(!flag&&(k-2*d1-d2)%3==0&&(k+d1-d2)%3==0&&(k+d1+2*d2)%3==0){
            flag=pd(k-2*d1-d2,k+d1-d2,k+d1+2*d2);
        }
        printf("%s\n",flag?"yes":"no");
    }
    return 0;
}
