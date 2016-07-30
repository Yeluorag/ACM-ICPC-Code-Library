#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define INF 0x3f3f3f3f
int ans,n,a[1000005],h[1000005];
set <int> po;
int main()
{
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a[i]);
        po.insert(a[i]);
    }
    ans=INF;
    int num=po.size();
    map <int,int> count;
    int s=0,t=0,cnt=0;
    for(;;){
        while(t<n&&cnt<num){
            if(count[a[t++]]++==0)
                cnt++;
        }
        if(cnt<num)break;
        ans=min(ans,t-s);
        if(--count[a[s++]]==0)
            cnt--;
    }
    printf("%d\n",ans);
    return 0;
}
