#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,y,x[1005],k[1005],flag,func[1005];
double dt[1005];
int abs(int a){return a>0?a:-a;}
int main()
{
    freopen("/Users/apple/input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&y);
    for(int i=0;i<n;i++)scanf("%d",&x[i]);
    int res=m;
    for(int i=0;i<n;i++){
        if(m*x[i]%y==0){
            k[i]=m*x[i]/y;
            res-=k[i];
            dt[i]=0;
        }else{
            double t=(double)m*(double)x[i]/(double)y;
            if(t-(int)t<(int)t+1-t)func[i]=-1;
            else func[i]=1;
            dt[i]=min(t-(int)t,(int)t+1-t);
        }
    }
    for(int i=0;i<n;i++){
        if(dt[i]>0){
            double t=(double)m*(double)x[i]/(double)y;
            k[i]=(int)t;
            if(func[i]==1) k[i]++;
            else k[i]--;
            if(k[i]>res)k[i]=res;
            res-=k[i];
        }
    }
    for(int i=0;i<n-1;i++)printf("%d ",k[i]);
    printf("%d\n",k[n-1]);
    return 0;
}