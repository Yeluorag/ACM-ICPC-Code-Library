#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	int n,a[5005],ans,flag=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
		a[i]=i+1;
	ans=n;
	if(n==3){
		ans=2;
		a[0]=1;a[1]=3;
	}else if(n==2){
		ans=1;a[0]=1;
	}else{
		for(int i=0;i<n-1;i++){
			if(flag){
				if(i+2>=n) break;
				swap(a[i],a[i+2]);
			}else swap(a[i],a[i+1]);
			flag=!flag;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<ans-1;i++)
		printf("%d ",a[i]);
	cout<<a[ans-1]<<endl;
	return 0;
}