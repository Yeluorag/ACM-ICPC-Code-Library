#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int t,n,f;
ll k,a[MAXN];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    cin>>t;
    while(t--){
        ll ans=0,head=-1;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(int i=0;i<n;i++){
            if(head<0) head=a[i];
            if(a[i]==a[i-1]+1) f=1;
            else if(a[i]==a[i-1]-1){
                if (f==1) head=a[i-1];
                f=2;
            }
            else { f=1;head=a[i];}
            if(head>0){
                if(f==1) {
                    if(a[i]>k)ans+=a[i]-head+1;
                }
                else{
                    if (a[i]>k) ans+=head-a[i]+1;
                    else ans+=head-k+1;
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}