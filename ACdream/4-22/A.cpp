#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,exp[1005],A[5],flag[1005];
bool ans;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    while(scanf("%d",&N)!=EOF){
        int res=0,cnt;
        ans=false;
        memset(flag,0,sizeof(flag));
        scanf("%d%d%d%d",&A[0],&A[1],&A[2],&A[3]);
        for(int i=0;i<N;i++){
            scanf("%d",&exp[i]);
            res+=exp[i];
        }
        cnt=N;
        sort(exp,exp+N);
        int idx=0,ret;
        while(A[idx]>0){
            ret=1;
            if(cnt==0){ans=false;break;}
            int i;
            for(i=0;i<N;i++){
                if(exp[i]>=A[idx]&&!flag[i]){
                    cnt--;
                    res-=exp[i];
                    flag[i]=1;
                    A[idx++]=0;
                    ret=0;
                    break;
                }
            }
            if(i--==N&&A[idx]>0&&ret){
                while(flag[i])i--;
                A[idx]-=exp[i];
                flag[i]=1;
                res-=exp[i];
                cnt--;
            }
            if(idx==4){
                ans=true;
                break;
            }
        }
        printf("%s",ans?"YES":"NO");
        if (ans)printf(" %d\n",res);
        else cout<<endl;
    }
    return 0;
}