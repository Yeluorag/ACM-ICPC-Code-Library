#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10005;
int cas,res[30];
char a[maxn],b[maxn];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&cas)&&cas!=-1){
        scanf("%s",a);
        scanf("%s",b);
        memset(res,0,sizeof(res));
        int flag=0,cnt=0;
        for(int i=0;i<strlen(a);i++) {
            if(res[a[i]-'A']==0) cnt++;
            res[a[i]-'A']=1;
        }
        for(int i=0;i<strlen(b);i++) {
            if(res[b[i]-'A']==0) flag++;
            else if(res[b[i]-'A']>0) cnt--;
            res[b[i]-'A']=-1;
            if(!cnt) break;
            if(flag==7) break;
        }
        printf("Round %d\n",cas);
        if(!cnt) printf("You win.\n");
        else if(flag==7) printf("You lose.\n");
        else if(cnt>0&&flag<7) printf("You chickened out.\n");
        
    }
    return 0;
}
