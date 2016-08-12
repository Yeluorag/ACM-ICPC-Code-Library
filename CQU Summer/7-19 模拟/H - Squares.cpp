#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h[15][15],v[15][15],cnt[15];
int n,m,flag,ans,cas=0;
char ins;

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        ans=0;
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++){
            int a,b;
            getchar();
            scanf("%c%d%d",&ins,&a,&b);
            if(ins=='H') h[a][b]=1;
            else v[b][a]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                for(int size=1;size<n;size++){
                    int x=i+size-1,y=j+size-1;
                    if(h[i][y]&&v[x][j]){
                        flag=1;
                        for(int k=j;k<j+size;k++) if(!h[i+size][k]){
                            flag=0;
                            break;
                        }
                        for(int k=i;k<i+size;k++) if(!v[k][j+size]){
                            flag=0;
                            break;
                        }
                        if(flag){
                            x+=0;y+=0;
                            cnt[size]++;
                            ans=1;
                        }
                    }else break;
                }
            }
        }
        if(cas) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",++cas);
        for(int i=1;i<n;i++)
            if(cnt[i]) printf("%d square (s) of size %d\n",cnt[i],i);
        if(!ans) printf("No completed squares can be found.\n");
    }
    return 0;
}
