//
//  4144 Bacon's Cipher.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-1.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int n;
char s[10005];
int main() {
    //freopen("/Users/apple/Documents/input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        for(int i=0;i<n;i+=5){
            int b=1,a=0;
            for(int j=4;j>=0;j--){
                if(s[i+j]<='9'&&s[i+j]>='0') a+=b;
                b*=2;
            }
            printf("%c",'A'+a);
        }
        cout<<endl;
    }
    return 0;
}