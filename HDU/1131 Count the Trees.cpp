//
//  1131 Count the Trees.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-26.
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

const int base=10000;

int h[105][100],ans[100];
void mul(int i,int k)
{
    int carry=0;
    for (int j=0; j<100; j++) {
        h[i][j]=h[i-1][j]*(4*i-2);
        h[i][j]+=carry;
        carry=h[i][j]/base;
        h[i][j]%=base;
    }
}
void divd(int i,int k)
{
    int carry=0;
    for (int j=99; j>=0; j--) {
        h[i][j]+=carry*base;
        carry=h[i][j]%k;
        h[i][j]/=k;
    }
}
void print()
{
    int t=99;
    while (ans[t]==0) {
        t--;
    }
    printf("%d",ans[t--]);
    for (int j=t; j>=0; j--) {
        printf("%04d",ans[j]);
    }
    cout<<endl;
}
int main()
{
    int n;
    memset(h, 0, sizeof(h));
    h[1][0]=1;
    for (int i=2; i<101; i++) {
        mul(i,4*i-2);
        divd(i,i+1);
    }
    while (scanf("%d",&n),n) {
        int carry;
        memcpy(ans, h[n], sizeof(h[n]));
        for (int i=1; i<=n; i++) {
            carry=0;
            for (int j=0; j<100; j++) {
                ans[j]*=i;
                ans[j]+=carry;
                carry=ans[j]/base;
                ans[j]%=base;
            }
        }
        print();
    }
    return 0;
}