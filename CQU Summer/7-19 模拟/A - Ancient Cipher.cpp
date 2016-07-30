#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1005],b[1005];
int ca[30],cb[30],ans=1;
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%s",a)!=EOF){
        scanf("%s",b);
        ans=1;
        memset(ca,0,sizeof(ca));
        memset(cb,0,sizeof(cb));
        for(int i=0;i<strlen(a);i++) ca[a[i]-'A']++;
        for(int i=0;i<strlen(b);i++) cb[b[i]-'A']++;
        sort(ca,ca+26);
        sort(cb,cb+26);
        for(int i=0;i<26;i++) if(ca[i]!=cb[i]) ans=0;
        printf("%s\n",ans?"YES":"NO");
    }
    return 0;
}
