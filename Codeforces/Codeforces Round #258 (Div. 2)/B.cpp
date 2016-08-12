#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int main()
{
    int n,l=-10,r=-10,flag=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            l=i;
            break;
        }
    }
    for(int i=n-1;i>0;i--){
        if(a[i]<a[i-1]){
            r=i;
            break;
        }
    }
    if(l>=0){
        int flag=1;
        for(int i=l;i<=(l+r)/2;i++){
            int t=a[i];
            a[i]=a[l+r-i];
            a[l+r-i]=t;
        }
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                flag=0;break;
            }
        }
        if(flag)printf("yes\n%d %d\n",l+1,r+1);
        else printf("no\n");
    }
    else printf("yes\n1 1\n");
    return 0;
}
