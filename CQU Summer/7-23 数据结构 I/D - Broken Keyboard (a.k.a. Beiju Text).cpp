#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100005;
int cur,last,nxt[maxn];
char a[maxn];
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%s",a+1)!=EOF){
    	int len=strlen(a+1),flag=0;
    	cur=last=0;
    	nxt[0]=0;
    	for(int i=1;i<=len;i++){
    		if(a[i]=='[') cur=0;
    		else if(a[i]==']') cur=last;
    		else{
    			nxt[i]=nxt[cur];
    			nxt[cur]=i;
    			if(cur==last) last=i;
    			cur=i;
    		}
    	}
 		for(int i=nxt[0];i!=0;i=nxt[i]) printf("%c",a[i]);	
    	puts("");
    }
    return 0;
}
