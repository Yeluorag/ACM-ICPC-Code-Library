#include <iostream>
#include <cstdio>
using namespace std;
float pay[12];
int main()
{
    float res=0;
    for(int i=0;i<12;i++){
        scanf("%f",&pay[i]);
        res+=pay[i];
    }
    printf("$%.2f",res/12);
    return 0;
}