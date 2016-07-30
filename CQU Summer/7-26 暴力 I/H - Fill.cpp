#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=205;

int T,d;
int flag[maxn][maxn],ans[maxn],mx[3];
struct node{
    int vol[3];
    int water;
    bool operator< (const node& a) const { return water>a.water; }
};

void bfs(){
    node st;
    st.vol[0]=0;st.vol[1]=0;
    st.vol[2]=mx[2];
    flag[0][0]=1;
    st.water=0;
    priority_queue<node> que;
    que.push(st);
    while(!que.empty()){
        node temp=que.top();que.pop();
        for(int i=0;i<3;i++) {
            if(ans[temp.vol[i]]==-1) ans[temp.vol[i]]=temp.water;
            else ans[temp.vol[i]]=min(ans[temp.vol[i]],temp.water);
        }
        int w=0,nt[3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j) continue;
                nt[0]=temp.vol[0],nt[1]=temp.vol[1],nt[2]=temp.vol[2];
                if(nt[i]<mx[i]){
                    w=min(nt[j],mx[i]-nt[i]);
                    nt[i]+=w;
                    nt[j]-=w;
                    if(!flag[nt[0]][nt[1]]){
                        node nxt;
                        flag[nt[0]][nt[1]]=1;
                        nxt.water=temp.water+w;
                        for(int k=0;k<3;k++)
                            nxt.vol[k]=nt[k];
                        nxt.water=temp.water+w;
                        que.push(nxt);
                    }
                }
            }
        }
    }
    
    
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&mx[0],&mx[1],&mx[2],&d);
        memset(ans,-1,sizeof(ans));
        memset(flag,0,sizeof(flag));
        bfs();
        for(int i=d;i>=0;i--){
            if(ans[i]>-1) {
                printf("%d %d\n",ans[i],i);
                break;
            }
        }
    }
    return 0;
}