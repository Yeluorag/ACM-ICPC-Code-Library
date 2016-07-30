#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int k,n,a[105],f[105];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    cin>>T;
    while(T--){
        memset(f, 0, sizeof(f));
        scanf("%d%d",&n,&k);
        int ans=1,cnt=n,c=1;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        while (cnt) {
            int flag=1;
            for (int i = 0; i < n; ++i){
                if(!f[i]){
                    if((a[i]-c)%k==0&&a[i]>=c){
                        f[i]=1;
                        cnt--;
                        flag=0;
                        c++;
                        break;
                    }
                }
            }
            if(flag){ans=0;break;}
        }
        printf("%s\n",ans?"Jerry ":"Tom");
    }
    return 0;
}