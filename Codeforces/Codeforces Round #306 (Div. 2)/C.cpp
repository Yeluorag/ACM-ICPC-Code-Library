#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ise[1005],a[105],ans=-1;
char num[105];

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","r",stdin);
    scanf("%s",num);
    int len=strlen(num);
    for(int i=0;i<len;i++)a[i]=num[i]-'0';
    for(int i=len-1;i>=0;i--){
        int t=a[i];
        if(t%8==0){ans=t;break;}
        for(int j=i-1;j>=0;j--){
            t=a[j]*10+a[i];
            if(t%8==0){ans=t;break;}
            for(int k=j-1;k>=0;k--){
                t=a[k]*100+a[j]*10+a[i];;
                if(t%8==0){ans=t;break;}
            }
        }
    }
    if(ans>-1)printf("YES\n%d\n",ans);
    else printf("NO\n");
    return 0;
}
