#include <iostream>
#include <cstdio>
using namespace std;
#define N 1005
class Solution {
public:
	bool isMatch(string s, string p) {
        bool ret = true;
        int i = 0, j = 0;
        for(;;) {
            if(p[i] == '/0')
        }

    } 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
    char a[N], b[N];
   for(int i = 0; i < 2; i ++) {
        scanf("%s", a);
        scanf("%s", b);
        printf("%s\n", cc.isMatch(a, b) ? "YES" : "NO");
    }
	return 0;

}