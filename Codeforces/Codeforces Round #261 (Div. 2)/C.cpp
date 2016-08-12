#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,d,a[1005][1005];
int main()
{
    int nd=0,tmp=1;
    scanf("%d%d%d",&n,&k,&d);
    while(tmp<n){
        if(k==1){
            printf("-1\n");
            return 0;
        }
        tmp*=k;
        nd++;
    }
    if(nd>d){
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        tmp=i;
        for(int j=0;j<d;j++){
            a[i][j]=tmp%k+1;
            tmp/=k;
        }
    }
    for(int j=0;j<d;j++){
        for(int i=0;i<n;i++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
