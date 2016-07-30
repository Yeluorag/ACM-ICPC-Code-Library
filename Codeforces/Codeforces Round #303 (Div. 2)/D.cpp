#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100005;
int a[N],num[N],f[N],n,ans=0;
int main(){
//  freopen("/Users/apple/input.txt","r",stdin);
//	freopen("/Users/apple/out.txt","r",stdin);
    memset(f,0,sizeof(f));
    scanf("%d",&n);
    sort(a,a+n);
    num[0]=0;
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=0;j<n;j++){
            if(!f[j]&&a[j]>=num[i]){
                ans++;
                num[i+1]=num[i]+a[j];
                f[j]=1;
                flag=0;
                break;
            }
        }
        if(flag)break;
    }
    printf("%d\n",ans);
    return 0;
}
