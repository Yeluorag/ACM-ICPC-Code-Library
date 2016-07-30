#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int ans,n,flag[11],cas=0;
int check(int a, int b )
{
    if ( b > 98765 ) return 0;
    for ( int i = 0 ; i < 10 ; ++ i )
        flag[i] = 0;
    if ( a < 10000 ) flag[0] = 1;
    while ( a ) {
        flag[a%10] = 1;
        a /= 10;
    }
    while ( b ) {
        flag[b%10] = 1;
        b /= 10;
    }
    int sum = 0;
    for ( int i = 0 ; i < 10 ; ++ i )
        sum += flag[i];
    return (sum == 10);
}
int main()
{
//    freopen("/Users/apple/input.txt","r",stdin);
    int n;
    while ( ~scanf("%d",&n) && n ) {
        if ( cas ++ ) puts("");
        ans = 0;
        for ( int i = 1234 ; i < 100000 ; ++ i ) {
            if ( check( i, i*n ) ) {
                printf("%05d / %05d = %d\n",i*n,i,n);
                ans ++;
            }
        }
        if ( !ans )
            printf("There are no solutions for %d.\n",n);
    }
    return 0;
}