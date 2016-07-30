#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int INF=1000000;
int n,k;
double l[10005];
bool cal(double m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(int)(l[i]/m);
    }
    return sum>=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lf",&l[i]);
    double lb=0,ub=INF;
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2;
        if(cal(mid)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    printf("%.2f\n",floor(ub*100)/100);
    return 0;
}
