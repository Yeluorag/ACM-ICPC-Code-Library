#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000005],f[1000005],g[1000005],n;
int fcal(int m){
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(a[i]==a[m])cnt++;
    }
    return cnt;
}
int gcal(int m){
    int cnt=1;
    for(int i=n;i>m;i--){
        if(a[i]==a[m])cnt++;
    }
    return cnt;
}

int main()
{
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i]=fcal(i);
        g[i]=gcal(i);
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++)
            if(f[i]>g[j])ans++;
    }
    printf("%I64d\n",ans);
    return 0;
}
