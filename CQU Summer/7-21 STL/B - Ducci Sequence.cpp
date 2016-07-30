#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set< vector<int> > all;
int n,m,flag;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>n;
    while(n--){
    	flag=0;
    	scanf("%d",&m);
    	vector<int>now;
    	for(int i=0;i<m;i++){
    		int t;
    		scanf("%d",&t);
    		now.push_back(t);
    	}
    	all.clear();
    	for(int i=0;i<10005;i++){
    		flag=0;
    		int t=now[0];
    		all.insert(now);
    		for(int i=0;i<m-1;i++)
    			now[i]=abs(now[i]-now[i+1]);
    		now[m-1]=abs(t-now[m-1]);
    		for(int i=0;i<m;i++)
    			if(now[i]) flag=1;
    		if(!flag) break;
    		if(all.count(now)){
    			flag=1;
    			break;
    		}
    	}
    	printf("%s\n",flag?"LOOP":"ZERO");
    }
    return 0;
}
