//
//  B.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-3-1.
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

const int MAXN=100005;
int n,a[MAXN],b[MAXN],c[MAXN],as1=-1,as2=-1;

int main()
{
    freopen("/Users/apple/Documents/input.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0; i<n; i++)   scanf("%d",&a[i]);
    for (int i=0; i<n-1; i++) scanf("%d",&b[i]);
    for (int i=0; i<n-2; i++) scanf("%d",&c[i]);
    sort(a, a+n);
    sort(b, b+n-1);
    sort(c, c+n-2);
    for (int i=0; i<n; i++) {
        if (a[i]!=b[i]&&as1<0) {
            as1=a[i];
        }
        if (b[i]!=c[i]&&i<n-1&&as2<0){
            as2=b[i];
        }
    }
    printf("%d\n%d\n",as1,as2);
    return 0;
}