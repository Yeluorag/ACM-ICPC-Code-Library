#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int T,ans;
map<ll,int> mp;
string s;

void dfs(int depth,int l,int r){
	if(s[l]=='['){
		int cnt=0;
		for(int i=l+1;i<r;i++){
			if(s[i]=='[') cnt++;
			if(s[i]==']') cnt--;
			if(s[i]==','&&!cnt){
				dfs(depth+1,l+1,i-1);
				dfs(depth+1,i+1,r-1);
			}
		}
	}else{
		ll num=0;
		for(int i=l;i<=r;i++) num=num*10+s[i]-'0';
		mp[num<<depth]++;
		ans++;
	}
}
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
    	cin>>s;
    	int len=s.size();
    	ans=0;
    	mp.clear();
    	dfs(0,0,len-1);
    	map<ll,int>::iterator ite;
    	int temp=0;
    	for(ite=mp.begin();ite!=mp.end();ite++) temp=max(temp,ite->second);
    	printf("%d\n",ans-temp);    	
    }
    return 0;
}