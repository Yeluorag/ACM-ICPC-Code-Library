#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, w, s, vis[105];
char str[105][105];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%s", str[i]);
    memset(vis, 0, sizeof(vis));
    scanf("%d,%d", &w, &s);
    int i = w - 1, k = n;
    while(k) {
        int cnt = s;
        for(; ; i++) {
            i %= n;
            if(vis[i]) continue;
            cnt --;
            if(!cnt) {
                vis[i] = 1;
                cout << str[i] << endl;
                i ++;
                break;
            }
        }
        k --;
    }
    return 0;
}