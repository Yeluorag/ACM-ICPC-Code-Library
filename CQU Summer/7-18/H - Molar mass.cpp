#include<stdio.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
  
const int maxn=200;  
char s[maxn];  
double ans[maxn];  
  
int num(int pos,int len)  
{  
    int temp;  
    for(int i=pos;i<len;i++)  
    {  
        if(s[i]<='9'&&s[i]>='0')  
            temp=i;  
        else  
            break;  
    }  
    int n=0;  
    for(int i=pos;i<=temp;i++)  
    {  
        n=n*10+(s[i]-'0');  
    }  
    return n-1;  
}  
  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        memset(ans,0,sizeof(ans));  
        scanf("%s",s);  
        int len=strlen(s);  
        int flag=0;  
        for(int i=0;i<len;i++)  
        {  
            if(s[i]=='C')  
                ans[i]=12.01;  
            if(s[i]=='H')  
                ans[i]=1.008;  
            if(s[i]=='O')  
                ans[i]=16.00;  
            if(s[i]=='N')  
                ans[i]=14.01;  
            if(s[i]>='1'&&s[i]<='9'&&flag==0)  
            {  
                ans[i]=ans[i-1]*num(i,len);  
                flag=1;  
            }  
            if(!(s[i]>='1'&&s[i]<='9'))  
            {  
                flag=0;  
            }  
        }  
        double sum=0;  
        for(int i=0;i<len;i++)  
        {  
            sum+=ans[i];  
        }  
        printf("%.3f\n",sum);  
    }  
    return 0;  
}  