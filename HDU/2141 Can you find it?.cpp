#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int l,n,m,r,p,cas=0;
int a[505],b[505],ab[400005],c[505],s[1005],ans[1005];
bool cal(int S){

    for(int i=0;i<m;i++){
        int ul=0,ur=p-1;
        while(ul<=ur){
            int mid=(ul+ur)/2;
            if(ab[mid]>S-c[i]) ur=mid-1;
            else if(ab[mid]<S-c[i]) ul=mid+1;
            else return true;
        }
    }
    return false;
}


int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //  freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&l,&n,&m)!=EOF){
        p=0;
        for(int i=0;i<l;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        for(int i=0;i<l;i++)for(int j=0;j<n;j++)ab[p++]=a[i]+b[j];
        sort(ab,ab+p);
        for(int i=0;i<m;i++)scanf("%d",&c[i]);
        scanf("%d",&r);
        for(int i=0;i<r;i++){
            scanf("%d",&s[i]);
            ans[i]=cal(s[i]);
        }
        printf("Case %d:\n",++cas);
        for(int i=0;i<r;i++)printf("%s\n",ans[i]?"YES":"NO");
    }
    return 0;
}
