#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int main()
{
    int n,flag=2,t;
    scanf("%d",&n);
    t=0;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            flag--;
            t=n-i-1;
        }
        if(!flag){
            t=-1;
            break;
        }
    }
    if(a[n-1]>a[0]&&flag<2)t=-1;
    printf("%d\n",t);
    return 0;
}
