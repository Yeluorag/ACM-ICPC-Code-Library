//
//  C.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-24.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pr;

struct node{
    int dgr;
    int s;
    int num;
    
}v[100000];

queue<node>que;
vector<pr>ans;
long long cnt=0;
int n,m,flag=0;

int main()
{
    freopen("/Users/apple/Documents/input.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        v[i].num=i;
        scanf("%d%d",&v[i].dgr,&v[i].s);
        cnt+=v[i].dgr;
        if (v[i].dgr==1) {
            que.push(v[i]);
        }
    }
    cout<<cnt/2<<endl;
    while (que.size()) {
        node t=que.front();
        que.pop();
        if (v[t.num].dgr!=1) {
            continue;
        }
        printf("%d %d\n",t.num,t.s);
        v[t.s].dgr--;
        t.dgr--;
        v[t.s].s^=t.num;
        if(v[t.s].dgr==1)que.push(v[t.s]);
    }
    return 0;
}
