#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int  State[9];

const int maxstate = 1000000;
State st[maxstate],goal,t;
int vis[370000],fact[9];
int dist[maxstate],T,w=0;
char p[50];
void init(){
    fact[0]=1;
    for(int i=1;i<9;i++)fact[i]=fact[i-1]*i;
}
int try_to_insert(int s){
    int code=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)if(st[s][j]<st[s][i])cnt++;
        code+=fact[8-i]*cnt;
    }
    if(vis[code])return 0;
    return vis[code]=1;
}

int bfs(){
    init();
    int front=1,rear=2;
    dist[1]=0;
    while(front<rear){
        State& s = st[front];
        int flag=1;
        /*for(int i=0;i<9;i++){
            if(goal[i]==-1)continue;
            if(goal[i]!=s[i])flag=0;
        }
//        printf("%d\n",dist[rear]);
        if(flag)return front;*/
        for(int i=0;i<12;i++){
            State& t=st[rear];
            memcpy(&t,&s,sizeof(s));
            switch(i){
                case 0:swap(t[0],t[3]);swap(t[3],t[6]);break;
                case 1:swap(t[1],t[4]);swap(t[4],t[7]);break;
                case 2:swap(t[2],t[5]);swap(t[5],t[8]);break;
                case 3:swap(t[6],t[3]);swap(t[3],t[0]);break;
                case 4:swap(t[7],t[4]);swap(t[4],t[1]);break;
                case 5:swap(t[8],t[5]);swap(t[5],t[2]);break;
                case 6:swap(t[0],t[1]);swap(t[1],t[2]);break;
                case 7:swap(t[3],t[4]);swap(t[4],t[5]);break;
                case 8:swap(t[6],t[7]);swap(t[7],t[8]);break;
                case 9:swap(t[2],t[1]);swap(t[1],t[0]);break;
                case 10:swap(t[5],t[4]);swap(t[4],t[3]);break;
                case 11:swap(t[8],t[7]);swap(t[7],t[6]);break;
                default:break;
            }
//            exg(i);
            dist[rear]=dist[front]+1;
            if(try_to_insert(rear))rear++;
        }
        front++;
    }
    return 0;
}



int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","r",stdin);
    scanf("%d",&T);
    while(w<T){
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        for(int i=0;i<9;i++)scanf("%d",&st[1][i]);
        for(int i=0;i<9;i++){
            char c[2]; scanf("%s",c);
            if(c[0]=='*') goal[i]=-1;
            else goal[i]=c[0]-'0';
        }
        int ans=bfs();
        printf("Case #%d: ",++w);
        if(ans>0)printf("%d\n",dist[ans]);
        else printf("No Solution!\n");
    }
    return 0;
}
