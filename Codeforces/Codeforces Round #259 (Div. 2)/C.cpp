#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)

double m,n;
int main()
{
    double ans;
    scanf("%lf%lf",&m,&n);
    for(int i=1;i<m;i++)
        ans+=pow((double)i/m,n);
    printf("%.12lf\n",m-ans);
    return 0;
}
