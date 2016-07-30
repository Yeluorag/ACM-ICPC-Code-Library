#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    char n[1000005];
    scanf("%s",n);
	int k=strlen(n);
	int t=(n[k-1]-'0')+(n[k-2]-'0')*10;
	printf("%d\n",t%4==0?4:0);
    return 0;
}
