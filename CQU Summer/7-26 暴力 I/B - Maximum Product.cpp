#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int n,s[20],cas=1;
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        long long ans=-1;
        for(int i=0;i<n;i++) scanf("%d",&s[i]);
        for(int i=0;i<n;i++){
            ll temp=1;
            for(int j=i;j<n;j++){
                temp*=(ll)s[j];
                ans=max(temp,ans);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",cas++,ans>0?ans:0);
        
    }
    return 0;
}