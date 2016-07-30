//
//  A.cpp
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

char maz[10][10];
int wt=0,bk=0;

int main()
{
    freopen("/Users/apple/Documents/input.txt","r",stdin);
    for (int i=0; i<8; i++) {
        scanf("%s",maz[i]);
        for(int j=0;j<8;j++){
            if (maz[i][j]>='a'&&maz[i][j]<='z') {
                switch (maz[i][j]) {
                    case 'q':wt+=9; break;
                    case 'r':wt+=5; break;
                    case 'b':wt+=3; break;
                    case 'n':wt+=3; break;
                    case 'p':wt+=1; break;
                    default:
                        break;
                }
            }else if(maz[i][j]>='A'&&maz[i][j]<='Z') {
                switch (maz[i][j]) {
                    case 'Q':bk+=9; break;
                    case 'R':bk+=5; break;
                    case 'B':bk+=3; break;
                    case 'N':bk+=3; break;
                    case 'P':bk+=1; break;
                    default:
                        break;
                }
            }
        }
    }
    printf("%s\n",wt>bk?"Black":bk==wt?"Draw":"White");
    return 0;
}