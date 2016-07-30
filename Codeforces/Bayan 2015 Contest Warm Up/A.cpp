#include <iostream>
#include <cstdio>
using namespace std;

int k;
char t;
int main()
{
    cin>>k;
    printf("+------------------------+\n|");
    for(int i=0;i<11;i++){
        if(i==0) t=k>0?'O':'#';
        else t=k-4-3*(i-1)>0?'O':'#';
        printf("%c.",t);
    }
    printf("|D|)\n|");
    for(int i=0;i<11;i++){
        if(i==0)t=k-1>0?'O':'#';
        else t=k-5-3*(i-1)>0?'O':'#';
        printf("%c.",t);
    }
    printf("|.|\n|%c.......................|\n|",k-2>0?'O':'#');
    for(int i=0;i<11;i++){
        if(i==0) t=k-3>0?'O':'#';
        else t=k-6-3*(i-1)>0?'O':'#';
        printf("%c.",t);
    }
    printf("|.|)\n+------------------------+");
    return 0;
}
