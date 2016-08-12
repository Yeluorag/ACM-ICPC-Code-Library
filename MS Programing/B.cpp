#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[1005];
char s[1005];
int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	int T,w=0;
	while(w<T){
		scanf("%s",s);
		int n=strlen(s),ans=0;
		for(int i=0 ;i<n;i++){
			for(int j=n-1;j>=0;j--){
				int a=i,b=j;
				while(a<=b){if(s[i++]==s[j--])ans++;}
			}
		}
		printf("Case #%d: %d\n",++w,ans);
	}
	return 0;
}