#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char m1[12], m2[12];
    int d1, y1, d2, y2;
    int T, w=0,ans;
    freopen("/Users/apple/input.txt", "r", stdin);
    cin>>T;
    while (w<T) {
        scanf("%s %d, %d", m1, &d1, &y1);
        scanf("%s %d, %d", m2, &d1, &y2);
        ans = 0;
        if(strcmp(m1,"January")==0 || (strcmp(m1,"February")==0&&d1<=29))y1--;

        if(strcmp(m2,"January")==0 || (strcmp(m2,"February")==0&&d2<29))y2--;
        ans = (y2>>2)-(y1>>2);
        ans = ans - (y2/100-y1/100);
        ans += ((y2/400-y1/400));
        printf("Case #%d: %d\n", ++w, ans);
    }
    return 0;
}