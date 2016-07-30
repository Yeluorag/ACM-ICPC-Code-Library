#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF=1500000000;
int b[200005];
int main()
{
    int n,mi=INF,ma=-INF,fi=0,fa=0,cnti=0,cnta=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        if(b[i]<mi){
            mi=b[i];
            cnti=1;
        }else if(b[i]==mi){
            cnti++;
        }
        if(b[i]>ma){
            ma=b[i];
            cnta=1;
        }else if(b[i]==ma){
            cnta++;
        }
    }
    if(ma!=mi)printf("%d %d\n",ma-mi,cnti*cnta);
    else printf("0 %d\n",cnta*(cnta-1)/2);
    return 0;
}
