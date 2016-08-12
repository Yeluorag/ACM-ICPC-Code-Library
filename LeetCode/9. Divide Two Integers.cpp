#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int flag = 1;
        if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
            flag = -1;
        LL left = abs((LL)dividend);
        LL right = abs((LL)divisor);
        LL pDivisor[33], pRes[33];
        int result = 0;
        pDivisor[1] = right;
        pRes[1] = 1;
        for(int i = 2; i < 33; i ++) {
            pDivisor[i] = pDivisor[i-1] * 2;
            pRes[i] = pRes[i-1] * 2;
            if(pDivisor[i] > (LL)INT_MAX + 1) {
                pDivisor[i] = 0;
                pRes[i] = 0;
            }
        }
        for(int i = 32; i >= 1; i --) {
            if(pDivisor[i] == 0) continue;
            if(left >= pDivisor[i]) {
                result += pRes[i];
                left -= pDivisor[i];
            }
        }
        return result * flag;
    }
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    int a, b;
    cin >> a >> b;
    cout << cc.divide(a, b) << endl;
    
    return 0;
    
}