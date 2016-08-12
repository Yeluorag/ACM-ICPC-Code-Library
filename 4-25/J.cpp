#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,w=0;
char a[10],b[10];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    cin>>T;
    char s[5]={'=','>','<'};
    while(w<T){
        int f1=0,f2=0,brc=0;
        scanf("%s",a);
        scanf("%s",b);
        int i=0;
        if(a[i]>b[i])f1=1;
        if(a[i]<b[i])f1=2;
        if(a[i+1]>b[i+1]){brc=1;}
        if(a[i+1]<b[i+1]){brc=2;}
        int j=2;
        if(a[j]>b[j])f2=1;
        else if(a[j]<b[j])f2=2;
        if(f2==0){
            int m=(a[j+1]-'0')*10+a[j+2]-'0',n=(b[j+1]-'0')*10+b[j+2]-'0';
            j+=3;
            if(m>n)f2=1;
            if(m<n)f2=2;
        }
        if(f2==0&&brc==0){
            if(a[j]>b[j])f2=1;
            else if(a[j]<b[j])f2=2;
        }
        printf("Case %d: %c %c\n",++w,s[f1],s[f2]);
    }
    return 0;
}