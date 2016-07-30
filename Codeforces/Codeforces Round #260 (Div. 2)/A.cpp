#include <iostream>
#include <cstdio>
#include <
using namespace std;

int a[100005],b[100005];
int main()
{
    int n,flag=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=x;
        b[a[i]]=y;
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        if(b[a[i]]>b[a[i+1]]){
            flag=0;
        }
        if(!flag)break;
    }
    printf("%s\n",flag?"Poor Alex":"Happy Alex");
    return 0;
}
