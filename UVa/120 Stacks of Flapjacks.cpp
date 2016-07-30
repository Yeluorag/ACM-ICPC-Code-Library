#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int maxn = 10000 + 5;


int getmax(int a[],int pos)
{int max=pos,i;
    for (i=1;i<pos;i++)
        if (a[i]>a[max]) max=i;
    return max;
};
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    int a[101],b[101],c[2000],step,i,j,num=1,max,pos;
    while (scanf("%d",&a[num])!=EOF)
    {
        while (getchar()!='\n')
        {++num;scanf("%d",&a[num]);}
        for (i=1;i<num;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[num]);
        pos=num; step=0;
        while (pos>0)
        {max=getmax(a,pos);
            if (max<pos)
            {if (max!=1) {++step; c[step]=num+1-max;}
                for (i=1;i<=max;i++)
                    b[max-i+1]=a[i];
                for (i=1;i<=max;i++)
                    a[i]=b[i];
                
                for (i=1;i<=pos;i++)
                    b[pos-i+1]=a[i];
                for (i=1;i<=pos;i++)
                    a[i]=b[i];
                ++step;  c[step]=num-pos+1;
            }
            --pos;
        }
        for (i=1;i<=step;i++)
            printf("%d ",c[i]);
        printf("0\n");
        num=1;
    }

    
    
    return 0;
}
