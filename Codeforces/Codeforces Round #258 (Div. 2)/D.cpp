#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100005];
long long cnt[2][2];
long long cal(long long n){return n*(n+1)/2;}

int main()
{
    scanf("%s",s);
    long long even=0,odd=0,n=strlen(s);
    for(int i=0;i<n;i++){
        ++cnt[i%2][s[i]-'a'];
    }
    odd=cal(cnt[0][0])+cal(cnt[0][1])+cal(cnt[1][0])+cal(cnt[1][1]);
    even=cnt[0][0]*cnt[1][0]+cnt[0][1]*cnt[1][1];
    printf("%I64d %I64d\n",even,odd);
    return 0;
}
