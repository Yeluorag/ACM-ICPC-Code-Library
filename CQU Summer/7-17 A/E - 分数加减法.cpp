#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c,d;
char t;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d/%d%c%d/%d",&a,&b,&t,&c,&d)!=EOF){
        int fm=b*d,fz1=a*d,fz2=b*c;
        if(t=='-') fz1-=fz2;
        else fz1+=fz2;
        int temp=gcd(fz1,fm);
        if(temp<0)temp=-temp;
        fz1/=temp;
        fm/=temp;
        if(fz1==0||fm==1)printf("%d\n",fz1);
        else printf("%d/%d\n",fz1,fm);
    }
    return 0;
}