//
//  1073 Online Judge.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-9.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 5005;

string a,b;
char s1[MAX],s2[MAX];
int T;

void input(char *str)
{
    char tmp[MAX];
    while (gets(tmp)&&strcmp(tmp, "END")) {
        if(strlen(tmp)==0) strcat(str, "\n");
        else strcat(str, tmp);
    }
}

void del(char *str,int len)
{
    char tmp[MAX];
    int t=0;
    for(int i=0;i<len;i++){
        if(str[i]!=' '&&str[i]!='\t'&&str[i]!='\n')
            tmp[t++]=str[i];
    }
    tmp[t]='\0';
    strcpy(str,tmp);
}
int cmp()
{
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    if (len1==len2&&!strcmp(s1,s2)) return 1;
    del(s1,len1);
    del(s2, len2);
    if (!strcmp(s1, s2)) {
        return 0;
    }else{
        return -1;
    }
}
int main()
{
    freopen("/Users/apple/Documents/input.txt","r",stdin);
    cin>>T;
    while(T--){
        strcpy(s1, "\0");
        strcpy(s2, "\0");
        input(s1);
        input(s2);
        int ans=cmp();
        if(ans==1)puts("Accepted");
        else if(ans==0)puts("Presentation Error");
        else puts("Wrong Answer");
    }
    return 0;
}
