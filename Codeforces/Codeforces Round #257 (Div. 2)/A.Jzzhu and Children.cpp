#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

unsigned long long ma(int x,int y){
    return x>y?x:y;
}
unsigned long long mi(int x,int y){
    return x<y?x:y;
}
int main()
{
    int n,m,k,mx,mm,t,p,ans=1;
    unsigned long long ans1,ans2;
    cin>>n>>m>>k;
    mx=ma(m,n);
    mm=mi(m,n);
    t=mx/(k+1);
    if(t>0) ans1=(unsigned long long)t*mm;
    else{
        p=mm/(k+2-mx);
        if(p>0) ans1=p;
        else 	ans=-1;
    }
    t=mm/(k+1);
    if(t>0)
		ans2=(unsigned long long)t*mx;
    else{
        p=mx/(k+2-mm);
        if(p>0) ans2=p;
        else 	ans=-1;
    }
	if(ans==1){
	    if(ans2>ans1)ans1=ans2;
	    cout<<ans1<<endl;
	}
	else cout<<ans<<endl;
    return 0;
}
