//
//  C.cpp
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

int n,m,ans;
int a[10],f[10],p[10];

void solve(){
    int c;
    for (int i=1; i<10; i++) {
        memset(f, 0, sizeof(f));
        c=0;
        p[c++]=a[i];
        f[a[i]]=1;
        for (int j=1; j<10; j++) {
            if (!f[a[j]]) {p[c++]=a[j];f[a[j]]=1;}
            else continue;
            for (int k; k<10; k++) {
                if (!f[a[k]]) { p[c++]=a[k];f[a[k]]=1;}
                else continue;
                for (int l=1; l<10; l++) {
                    if (!f[a[l]]) { p[c++]=a[l];f[a[l]]=1;}
                    else continue;
                    for (int m=1; m<10; m++) {
                        if (!f[a[m]]) { p[c++]=a[m];f[a[m]]=1;}
                        else continue;
                        for (int n=1; n<10; n++) {
                            if (!f[a[n]]) { p[c++]=a[n];f[a[n]]=1;}
                            else continue;
                            for (int r=1; r<10; r++) {
                                if (!f[a[r]]) { p[c++]=a[r];f[a[r]]=1;}
                                else continue;
                                for (int s=1; s<10; s++) {
                                    if (!f[a[s]]) { p[c++]=a[s];f[a[s]]=1;}
                                    else continue;
                                    for (int t=1; t<10; t++) {
                                        if (!f[a[n]]) { p[c++]=a[n];f[a[n]]=1;}
                                        else continue;
                                        if (((10*p[4]+p[5])*p[0]+(10*p[1]+p[2])*p[3])*(10*p[7]+p[8])==(10*p[1]+p[2])*(10*p[4]+p[5])*p[6]) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    ans=0;
    solve();
    cout<<ans/2;
    return 0;
}