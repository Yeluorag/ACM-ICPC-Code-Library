#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const float pi=3.14159;
int main()
{
    int N,w=1;
    scanf("%d",&N);
    while(w<=N){
        float x,y,R;
        scanf("%f%f",&x,&y);
        R=sqrt(x*x+y*y);
        int year=ceil(pi*R*R/100);
        printf("Property %d: This property will begin eroding in year %d.\n",w++,year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
