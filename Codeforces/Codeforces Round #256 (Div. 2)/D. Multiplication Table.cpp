#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
ll k,n,m;
ll min(ll x,ll y){return x<y?x:y;}

int main()
{
    cin>>n>>m>>k;
    ll l=1,r=n*m,ans;
    while(l<=r){
        ll mid=(l+r)>>1,num=0;
        for(ll i=1;i<=n;i++)
           num+=min(m,mid/i);
        if(num>=k){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<endl;
}
