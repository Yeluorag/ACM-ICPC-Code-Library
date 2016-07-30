#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

char a[100005],f=0;
vector<int> v1,v2;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","r",stdin);
    scanf("%s",a);
    int n=strlen(a);
    rep(i,n-1){
    	if(a[i]=='A'&&a[i+1]=='B') v1.push_back(i);
    	if(a[i]=='B'&&a[i+1]=='A') v2.push_back(i);
    }
    if(v1.size()&&v2.size()) if((v1[0]<v2[v2.size()-1]-1)||v2[0]<v1[v1.size()-1]-1)f=1;
    printf("%s\n",f?"YES":"NO");
    return 0;
}
