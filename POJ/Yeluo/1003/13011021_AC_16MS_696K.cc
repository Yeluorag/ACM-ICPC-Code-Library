#include <iostream>
#include <cstdio>
using namespace std;

float hang(int n){
    float sum=0;
    for(int i=2;i<=n+1;i++)
        sum+=(float)1/i;
    return sum;
}

int main(){
    float c;
    while(scanf("%f",&c)&&c!=0.00){
        int n=0;
        float sum=0;
        while(sum<c){
            n++;
            sum=hang(n);
        }
        printf("%d card(s)\n",n);
    }
    return 0;
}