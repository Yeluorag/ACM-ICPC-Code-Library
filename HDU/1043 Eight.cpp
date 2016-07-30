
//  main.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-1.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef int State[9];
const int MaxHash = 400005;


struct node{
    int state[9];
    int hash;
    int h,g;
    bool operator<(const node n1)const{     
        if(h+g==n1.h+n1.g)return g<n1.g;
        return h+g>n1.h+n1.g;
    }
};

node start,goal;
int vis[MaxHash],fact[9],pre[MaxHash],dir[MaxHash];
char str[105];

const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

void init(){
    memset(vis, 0, sizeof(vis));
    memset(dir, -1, sizeof(dir));
    memset(pre, -1, sizeof(pre));
    fact[0]=1;
    for(int i=1;i<9;i++) {
        fact[i]=fact[i-1]*i;
        goal.state[i-1]=i;
    }
    goal.state[8]=0;
}

int findHash(int *t){
    int code =0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)if(t[j]<t[i])cnt++;
        code+=fact[8-i]*cnt;
    }
    return code;
}

int tryto(int *s){
    int code=findHash(s);
    return vis[code]?0:vis[code]=1;
}

int check(){
    int cnt=0;
    node s=start;
    for (int i=0; i<9; i++) {
        if (s.state[i]==0) continue;
        for (int j=i-1; j>=0; j--) {
            if (s.state[i]==0) continue;
            if (s.state[j]>s.state[i]) cnt++;
        }
    }
    return (cnt+1)%2;
}

bool done(node a,node b){
    for (int i=0; i<9; i++) if (a.state[i]!=b.state[i]) return false;
    return true;
}

void print(){
    string ans;
    ans.clear();
    int nxt=findHash(goal.state);
    while(pre[nxt]!=-1){
        switch(dir[nxt]){
            case 0:ans+='d';break;
            case 1:ans+='u';break;
            case 2:ans+='r';break;
            case 3:ans+='l';break;
            default:break;
        }
        nxt=pre[nxt];
    }
    for(int i=ans.size()-1;i>=0;i--)putchar(ans[i]);
    printf("\n");
}

int get_h(node tmp){   //获得估价函数H
    int ans=0;
    for(int i=0;i<9;i++)
            if(tmp.state[i])
                ans+=abs(i/3-(tmp.state[i]-1)/3)+abs(i%3-(tmp.state[i]-1)%3);
    return ans;
}


bool bfs(){
    init();
    priority_queue<node>que;
    que.push(start);
    while(!que.empty()){
        node s=que.top();que.pop();
        vis[findHash(s.state)]=1;
        if(done(s, goal)){
            return true;
        }
        int z;
        for(z=0;z<9;z++)if(!s.state[z])break;
        int x=z/3,y=z%3;
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            int nz=nx*3+ny;
            node t;
            t=s;
            if(nx>=0&&nx<3&&ny>=0&&ny<3){
                swap(t.state[z], t.state[nz]);
                t.g=s.g;
                s.hash=findHash(s.state);
                t.hash=findHash(t.state);
                if(tryto(t.state)){

                    t.g+=1;
                    t.h=get_h(t);
                    vis[t.hash]=1;
                    pre[t.hash]=s.hash;
                    dir[t.hash]=d;
                    que.push(t);
//                    printf("%d: g:%d h:%d  d:%d\n",t.hash,t.g,t.h,d);

                }
            }
        }
    }
    return false;
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    while (gets(str)) {
        int idx=0;
        int len=strlen(str);
        for(int i=0;i<len;i++){
            if (str[i]=='x') start.state[idx++]=0;
            else if(str[i]>'0'&&str[i]<'9')start.state[idx++]=str[i]-'0';
        }
        if (!check()) {
            printf("unsolvable\n");
            continue;
        }
        bool res=bfs();
        if(res)print();
        else printf("unsolvable\n");
    }
    return 0;
}