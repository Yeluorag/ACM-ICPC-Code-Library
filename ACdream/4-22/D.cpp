#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,c[105],num[105];
bool cmp(int a,int b){ return a>b;}
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        int ans=0;
        for(int i=0;i<n;i++)scanf("%d",&c[i]);
        sort(c,c+n,cmp);
        int cnt=0,k=1;
        for(int i=0;i<n;i++){
            ans+=k*c[i];
            cnt++;
            if(cnt==m){cnt=0;k++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}