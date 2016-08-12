#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

char word[120005][30],temp[30];
map<string,int> mp;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    int n=0;
    mp.clear();
    while(scanf("%s",word[n])!=EOF){
    	mp[word[n++]]=1;
    }
    for(int i=0;i<n;i++){
    	int len=strlen(word[i]);
    	for(int j=0;j<len-1;j++){
    		char t1[30],t2[30];
    		strncpy(t1,word[i],j);
    		strncpy(t2,word[i]+j,len-j);
    		if(mp[t1]&&mp[t2]){
    			printf("%s\n",word[i]);
    			break;
    		}
    	}
    }

    return 0;
}
