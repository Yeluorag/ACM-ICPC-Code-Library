#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int x,y,n,k,ans;
    cin>>x>>y>>n;
    k=n%6;
    if(k==1) ans=x%1000000007;
    else if(k==2)ans=y%1000000007;
    else if(k==3)ans=(y-x)%1000000007;
    else if(k==4)ans=(-x)%1000000007;
    else if(k==5)ans=(-y)%1000000007;
    else if(k==0)ans=(x-y)%1000000007;
    while(ans<0){ans+=1000000007;}
    cout<<ans<<endl;
    return 0;
}
