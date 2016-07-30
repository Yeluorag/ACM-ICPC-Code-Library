#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,ans;


int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	cin>>n;
	if(n==1)ans=1;
	else if(n==2) ans=2;
	else if(n==3) ans=6;
	else{
		if(n%2==1)ans=n*(n-1)*(n-2);
		else {
			ans=(n-1)*(n-2)*(n-3);
			ans=max(ans,n*(n-1)*(n-3));
		}
	}
	cout<<ans<<endl;
	return 0;
}