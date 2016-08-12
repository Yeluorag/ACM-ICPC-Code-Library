#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int k,n,a[20];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    cin>>T;
    char s[15]={'p','q','r','u','v','w','x','y','z'};
    while(T--){
        int flag=0;
        for(int i=0;i<10;i++)scanf("%d",&a[i]);
        for(int i=0;i<10;i++){
            if(i==9){
                if(!flag){printf("%d\n",a[i]);break;}
                if(a[i]!=0){
                    if(a[i]>0)printf("+");
                    printf("%d\n",a[i]);break;
                }
                else cout<<endl;
            }
            if(a[i]==0)continue;
            else {
                if(a[i]>0){
                    if(flag)printf("+");
                    if(a[i]>1)printf("%d%c",a[i],s[i]);
                    else printf("%c",s[i]);
                }
                if(a[i]<0){
                    if(a[i]<-1)printf("%d%c",a[i],s[i]);
                    else printf("-%c",s[i]);
                }
                flag=1;
            }
        }
    }
    return 0;
}