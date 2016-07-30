#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int cnt[10],T,cas=0;
string str;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","r",stdin);
    cin>>T;
    getline(cin,str);
    while(cas<T){
    	memset(cnt,0,sizeof(cnt));
    	getline(cin,str);
    	int len=str.length();
    	for(int i=0;i<len;i++){
    		if(str[i]=='g')cnt[0]++;
			else if(str[i]=='o')cnt[1]++;
			else if(str[i]=='d')cnt[2]++;
			else if(str[i]=='m')cnt[3]++;
			else if(str[i]=='n')cnt[4]++;
			else if(str[i]=='r')cnt[5]++;
			else if(str[i]=='i')cnt[6]++;
			else if(str[i]==' ')cnt[7]++;
    	}
    	if(cnt[0])cnt[0]--;
    	cnt[1]/=3;cnt[4]/=2;
    	int ans=*min_element(cnt,cnt+7);
    	printf("Case #%d: %d\n",++cas,ans);
    }

    return 0;
}
