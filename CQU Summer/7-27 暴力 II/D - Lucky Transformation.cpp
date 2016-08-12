#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;

char d[maxn];
int n, k;

int main(){
//    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    cin >> n >> k;
    scanf("%s", d+1);
    int x = 0, ret = 0;
    for(int i = 1; i <= k; i++) {
        if(ret) break;
        int flag = 0;
        if(x >= n) break;
        for(int j = x + 1; j <=n; j++) {
            
            if(flag) break;
            if(d[j] == '4' && d[j+1] =='7') {
                flag = 1;
                if(j % 2 == 0) {
                    if(d[j-1] == '4'){
                        ret = 1;
                        if((k - i) % 2 == 0) d[j] = '7';
                    }
                    else d[j] = '7';
                }
                else {
                    if(d[j+2] == '7') {
                        ret = 1;
                        if((k - i) % 2 == 0) d[j+1] = '4';
                    } else d[j+1] = '4';
                }
            }
            x = j + 1;
        }
    }
    printf("%s\n", d+1);
    
    return 0;
}