#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++){
        for(int j=0;j<(n-2*i+1)/2;j++)
            printf("*");
        for(int j=0;j<2*i-1;j++)
            printf("D");
        for(int j=0;j<(n-2*i+1)/2;j++)
            printf("*");
        printf("\n");
    }
    for(int i=0;i<n;i++)
        printf("D");
    printf("\n");
    for(int i=n/2;i>=1;i--){
         for(int j=0;j<(n-2*i+1)/2;j++)
            printf("*");
        for(int j=0;j<2*i-1;j++)
            printf("D");
        for(int j=0;j<(n-2*i+1)/2;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
