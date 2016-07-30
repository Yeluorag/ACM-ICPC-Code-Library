#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int t,x,y;

void setbit(int &n, int b) {
    n |= 1 << b;
}

void clrbit(int &n, int b) {
    n &= ~(1 << b);
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%x,%d,%d", &t, &x, &y)==3) {
        clrbit(t, x);
        setbit(t, y);
        setbit(t, y - 1);
        clrbit(t, y - 2);
        printf("%x\n", t);
    }
    return 0;
}