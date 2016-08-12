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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m;

// Imp

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    double M[20][40];  
    LL E[20][40];  
  
    for(int i = 0; i <= 9; ++i) for(int j = 1; j <= 30; ++j) {  
        double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;  
        double t = log10(m) + e * log10(2);  
        E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);  
    }  
  
    string in;  
    while(cin >> in && in != "0e0") {  
        for(string::iterator i = in.begin(); i != in.end(); ++i) if(*i == 'e') *i = ' ';  
        istringstream ss(in);  
        double A; int B;  
        ss >> A >> B;  
        while(A < 1) A *= 10, B -= 1;  
        rep(i, 10) FOR(j, 1, 30) {  
            if(B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {  
                cout << i << ' ' << j << endl;  
                break;  
            }  
        }  
    }  
    
    return 0;
}