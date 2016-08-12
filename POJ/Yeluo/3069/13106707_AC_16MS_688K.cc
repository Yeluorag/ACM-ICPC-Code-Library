#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,R,x[1001];
    while(scanf("%d%d",&R,&n)&&n!=-1&&R!=-1){
        int ans=0,i=0;
        for(int i=0;i<n;i++)
            scanf("%d",&x[i]);
        int p=x[0];
        sort(x,x+n);
        while(i<n){
          int s=x[i++];
          while(i<n&&x[i]<=s+R)i++;
          int p=x[i-1];
          while(i<n&&x[i]<=p+R)i++;
          ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
