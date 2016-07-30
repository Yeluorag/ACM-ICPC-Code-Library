#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int ans=-1;
char s[105];
map<string,int>mp;
string res;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%s",s)!=EOF){
    	mp.clear();
    	ans=-1;
    	res="-1";
	    for(int i=0;i<strlen(s);i++){
	    	string t;
	    	for(int j=i;j<strlen(s);j++){
	    		t+=s[j];
	    		if(s[j]!='4'&&s[j]!='7') break;
	    		mp[t]++;
	    	}
	    }
	    map<string,int>::iterator ite;
	    for(ite=mp.begin();ite!=mp.end();ite++){
	    	if(ite->second>ans) {
	    		ans=ite->second;
	    		res=ite->first;
	    	}else if(ite->second==ans&&ite->first<res) res=ite->first;
	    }
    
    	cout<<res<<endl;
    }
    return 0;
}