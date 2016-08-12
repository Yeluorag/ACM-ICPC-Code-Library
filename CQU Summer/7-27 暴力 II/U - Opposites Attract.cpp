#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll cnt[30],ans=0;
int n,t;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    while(n--) {
    	scanf("%d",&t);
    	cnt[t+10]++;
    }
    for(int i=0;i<10;i++){
    	ans+=cnt[i]*cnt[20-i];
    }
    if(cnt[10]) ans+=cnt[10]*(cnt[10]-1)/2;
    cout<<ans<<endl;
    return 0;
}