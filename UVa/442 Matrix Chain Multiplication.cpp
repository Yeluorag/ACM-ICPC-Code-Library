#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n;
struct Matrix {
    int a, b;
    Matrix(int a = 0, int b = 0):a(a), b(b) {}
} m[26];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n); getchar();
    for(int i = 0; i < n; i ++) {
        char c;
        int x, y;
        scanf("%c %d %d\n", &c, &x, &y);
        m[c - 'A'].a = x, m[c - 'A'].b = y;
    }
    
    string expr;
    while(cin >> expr) {
        int len = expr.length();
        bool error = false;
        stack<Matrix> s;
        int ans = 0;
        for(int i = 0; i < len; i ++) {
            if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
            else if(expr[i] == ')') {
                Matrix right = s.top(); s.pop();
                Matrix left = s.top(); s.pop();
                if(left.b != right.a) { error = true; break; }
                else {
                    ans += left.a * left.b * right.b;
                    left.b = right.b;
                    s.push(left);
                }
            }
        }
        if(error) puts("error");
        else printf("%d\n", ans);
    }
    
    
    return 0;
}