//
//  ACM 2.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-4-2.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int s[1005],cnt,n,L,pos,flag;

bool isHard(){
    for (int i=pos-1; i>=pos/2; i--) {
        flag=1;
        if (s[pos]==s[i]) {
            int j=i-1,k=pos-1;
            while (k>i&&flag) if (s[k--]!=s[j--])flag=0;
        }else flag=0;
        if (flag) return false;
    }
    return true;
}

int main(){
    freopen("/Users/apple/Documents/input.txt", "r", stdin);
    while (scanf("%d%d",&n,&L),n) {
        memset(s, -1, sizeof(s));
        pos=0;
        cnt=0;
        while (cnt<n) {
            s[pos]++;
            if (isHard()) {
                cnt++;
                pos++;
            }
            if (s[pos]==L-1) while (s[pos]==L-1) {s[pos]=-1;pos--;}
        }
        for (int i=0; i<pos; i++){
            printf("%c",s[i]+'A');
            if (i%4==3) {
                if(i%64==63) printf("\n");
                else if(i!=pos-1)printf(" ");
            }
        }
        if(pos%64)printf("\n");
        printf("%d\n",pos);
    }
    return 0;
}

