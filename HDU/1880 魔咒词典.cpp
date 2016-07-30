//
//  1880 魔咒词典.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-2.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,string> ss;
string a,b;
char s[150];
int n;
int main()
{
    //freopen("/Users/apple/Documents/input.txt","r",stdin);
    while (gets(s)&&s[0]!='@') {
        char at[100],bt[100];
        int i=1,j=1;
        at[0]='[';
        while(s[j]!=']')
            at[i++]=s[j++];
        at[i]=']';
        at[i+1]='\0';
        j+=2;
        i=0;
        while(s[j]!='\0')
            bt[i++]=s[j++];
        bt[i]='\0';
        a=at;
        b=bt;
        ss[a]=b;
        ss[b]=a;
    }
    scanf("%d",&n);
    gets(s);
    while(n--){
        gets(s);
        a=s;
        map<string,string>::iterator ite=ss.find(a);
        if(ite==ss.end())cout<<"what?"<<endl;
        else {
            b=ite->second;
            if(b[0]=='[')
                b=b.substr(1,b.length()-2);
            cout<<b<<endl;
        }
    }
    return 0;
}