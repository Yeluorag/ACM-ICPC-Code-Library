#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,flag[10005];
vector<int> num;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=1000;i++){
    	int temp=i,vis=1;
    	while(temp){
    		if(temp%10!=4&&temp%10!=7){
    			vis=0;
    			break;
    		}
    		temp/=10;
    	}
    	if(vis) {
    		flag[i]=1;
    		num.push_back(i);
    	}
    }
    for(int i=1;i<=1000;i++){
    	if(flag[i]){
    		for(int j=1;j<300;j++){
    			if(j*i>1000)break;
    			flag[i*j]=1;
    		}
    	}
    }
    while(scanf("%d",&n)!=EOF){
    	printf("%s\n",flag[n]?"YES":"NO");
    
    }
    return 0;
}