#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char in[30],pre[30];
int len;
void dfs(int l1,int r1,int l2,int r2){
    if(l1>r1) return;
    char rt=pre[l1];
    int pos=l2;
    while(in[pos]!=rt)pos++;
    int cnt=pos-l2;
    dfs(l1+1, l1+cnt, l2, pos-1);
    dfs(l1+cnt+1, r1, pos+1, r2);
    printf("%c",rt);
}
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //  freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%s%s",pre,in)==2){
        len=strlen(in);
        dfs(0,len-1,0,len-1);
        puts("");
    }
    return 0;
}