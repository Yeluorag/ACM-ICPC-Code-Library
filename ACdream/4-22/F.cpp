#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a,b,x[105];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        int res=-1,ans,l=0,r=-1;
        for(int i=0;i<n;i++)scanf("%d",&x[i]);
        sort(x,x+n);
        while(x[l]<a&&l<n)l++;
        while(x[r]<=b&&r<n)r++;
        if(l<n&&l>0){
            if((x[l]+x[l-1])/2>=a&&(x[l]+x[l-1])/2<=b){
                if((x[l]-x[l-1])/2>res){
                    ans=(x[l]+x[l-1])/2;
                    res=(x[l]-x[l-1])/2;
                }
            }
        }
        if(l==0||(x[l]+x[l-1])/2<a){
            if(x[l]-a>res){
                ans=a;
                res=x[l]-a;
            }
        }
        for(int i=l+1;i<r;i++){
            if((x[i]-x[i-1])/2>res){
                ans=(x[i]+x[i-1])/2;
                res=(x[i]-x[i-1])/2;
            }
        }
        if(r<n){
            if((x[r]+x[r-1])/2<=b&&(x[r]+x[r-1])/2>=a){
                if((x[r]-x[r-1])/2>res){
                    ans=(x[r]+x[r-1])/2;
                    res=(x[r]-x[r-1])/2;
                }
            }
        }
        if(r==n||(x[r]+x[r-1])/2>b){
            if(b-x[r-1]>res)ans=b;
        }
        if(l==n)ans=b;
        printf("%d\n",ans);
        
    }
    return 0;
}