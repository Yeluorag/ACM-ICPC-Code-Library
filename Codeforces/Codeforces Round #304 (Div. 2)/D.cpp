#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=5000005;
int num[MAX];
bool isp[MAX];

int a,b,t,ans,cnt;

//θ(n(logn)^2)
void init(){
	memset(num,0,sizeof(num));
	memset(isp,true,sizeof(isp));
	isp[1]=false;
	for(int i=2;i<=MAX;i++){
		if(isp[i]){
			for(int j=i;j<MAX;j+=i){
				int temp=j;
				while(temp%i==0){
					num[j]++;
					temp/=i;
				}
				isp[j]=false;
			}
		}
	}
	for(int i=2;i<MAX;i++)num[i]+=num[i-1];
}

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","r",stdin);
    init();
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&a,&b);
    	printf("%d\n",num[a]-num[b]);
    }

    return 0;
}
