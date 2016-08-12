#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX=1005;

int T,n,k[MAX],w=0,f[MAX];

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","r",stdin);
    cin>>T;
    while(w<T){
        memset(f,0,sizeof(f));
          scanf("%d",&n);
        for(int i=0;i<n;i++){scanf("%d",&k[i+1]);f[i+1]=1;}
        bool b1=1,b2=1,h1=1,h2=1;
        for(int i=1;i<=n;i++){
            if(2*i>n)break;
            if(b1){
                if(k[2*i]>=k[i]&&f[2*i])b1=0;
                if(k[2*i+1]<=k[i]&&f[2*i+1])b1=0;
            }
            if(b2){
                if(k[2*i]<=k[i]&&f[2*i])b2=0;
                if(k[2*i+1]>=k[i]&&f[2*i+1])b2=0;
            }
            if(h1){
                if(k[2*i]<k[i]&&f[2*i])h1=0;
                if(k[2*i+1]<k[i]&&f[2*i+1])h1=0;
            }
            if(h2){
                if(k[2*i]>k[i]&&f[2*i])h2=0;
                if(k[2*i+1]>k[i]&&f[2*i+1])h2=0;
            }
        }
        bool b=b1||b2,h=h1||h2;
        printf("Case #%d: ",++w);
        if(b&&h)printf("Both\n");
        else if(b&&!h)printf("BST\n");
        else if(!b&&h)printf("Heap\n");
        else printf("Neither\n");
        
    }
    return 0;
}
