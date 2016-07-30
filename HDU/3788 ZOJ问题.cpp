//
//  3788 ZOJ问题.cpp
//  
//
//  Created by I‘m a Mac on 15-1-1.
//
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char s[1005];
int n,a,b,c,x,ans;
void init()
{
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='z'){
            a=cnt;
            cnt=0;
        }else if(s[i]=='j'){
            b=cnt;
            cnt=0;
        }else if(s[i]=='o') cnt++;
        c=n-2-a-b;
    }
}
int main()
{
    while(scanf("%s",s)!=EOF){
        ans=0;
        n=strlen(s);
        init();
        if(c==a*b)ans=1;
        if(b==0)ans=0;
        printf("%s\n",ans?"Accepted":"Wrong Answer");
    }
    return 0;
}

