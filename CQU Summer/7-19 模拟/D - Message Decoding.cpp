// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, len, value;;
int key[8][1<<8];
char code[N];
// Imp
void read() {
    int sz = strlen(code);
    value = 0, len = 1;
    rep(i, sz) {
        if(value < (1 << len) - 1) key[len][value++] = code[i];
        else value = 0, key[++len][value++] = code[i];
    }
}

void print() {
    value = 0;
    char c;
    rep(i, len) {
        do scanf("%c", &c); while(!isdigit(c));
        value = value * 2 + c - '0';
    }
    if(value >= (1 << len) - 1) return;
    putchar(key[len][value]);
    print();
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(gets(code) != NULL) {
        if(!code[0]) continue;
        mem(key, 0);
        read();
        int a, b, c;
        while(scanf("%1d%1d%1d", &a, &b, &c), len = 4 * a + 2 * b + c) print();
        puts("");
        getchar();
    }
    
    
    return 0;
}