#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);i++)

int n,k,ans,mk,flag[105][105];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char maz[105][105];
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    memset(flag,0,sizeof(flag));
    cin>>n>>k;
    mk=(n*n+1)/2;
    ans=k>mk?0:1;
    rep(i,n)rep(j,n)maz[i][j]='S';
    if(ans){
        int cnt=k;
        while(cnt){
            rep(i,n){rep(j,n){
                    if(!flag[i][j]){
                        flag[i][j]=1;
                        maz[i][j]='L';
                        rep(k,4){
                            int nx=i+dx[k],ny=j+dy[k];
                            if(nx>=0&&nx<n&&ny>=0&&ny<n){
                                flag[nx][ny]=1;
                            }
                        }
                        cnt--;
                        if(!cnt)break;
                    }
                }
                if(!cnt)break;
            }
        }
        printf("YES\n");rep(i,n)printf("%s\n",maz[i]);
    }else printf("NO\n");
    return 0;
}