#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    void get_next(string needle, int nxt[]) {
        int k = -1;
        nxt[0] = -1;
        for(int i = 1; i < needle.length(); i ++) {
            while(k != -1 && needle[k+1] != needle[i])
                k = nxt[k];
            if(needle[i] == needle[k+1])
                nxt[i] = ++ k;
            else
                nxt[i] = -1;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int ret = -1;
        int len = needle.length();
        int nxt[len];
        get_next(needle, nxt);
        int k = -1;
        for(int i = 0; i < haystack.length(); i ++) {
            while(k != -1 && haystack[i] != needle[k+1])
                k = nxt[k];
            if(haystack[i] == needle[k+1])
                k ++;
            if(k == len - 1) return ret = i - len + 1;
        }
        return ret;
    } 
};

int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    string hay, need;
    cin >> hay;
    cin >> need;
    cout << cc.strStr(hay, need) << endl;
    
    return 0;
    
}