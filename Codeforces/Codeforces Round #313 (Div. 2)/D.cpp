#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200005;
char a[maxn],b[maxn];
int ans=0;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    scanf("%s",a);
    scanf("%s",b);
    int len=strlen(a),l2=strlen(b);
    if(len==l2){
    	for(int i=1;i<len;i++){
    		char a1[maxn]="\0",a2[maxn]="\0",b1[maxn]="\0",b2[maxn]="\0";
    		strncpy(a1,a,i);
    		strncpy(a2,a+i,len-i);
    		strncpy(b1,b,i);
    		strncpy(b2,b+i,len-i);
    		if(strcmp(a1,b2)==0&&strcmp(a2,b1)==0){
    			ans=1;
    			break;
    		}
    	}
    }
    printf("%s\n",ans?"YES":"NO");
    return 0;
}
