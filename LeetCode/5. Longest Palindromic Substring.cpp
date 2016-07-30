#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int l = 0, r = 0, mx = 0, len;
		len = s.length();
		for(int i = 0; i < len; i ++) {
			int j, k;
			for(j = i - 1, k = i + 1; j >= 0 && k < len && s[j] == s[k]; j --, k ++);
			j ++, k --;
			if(k - j + 1 > mx) { mx = k - j + 1; l = j; r = k; }
			for(j = i, k = i + 1; j >= 0 && k < len && s[j] == s[k]; j --, k ++);
			j ++, k --;
			if(k - j + 1 > mx) { mx = k - j + 1; l = j; r = k; }
		}
		string ans = "";
		for(int i = l; i <= r; i ++) ans += s[i];
		return ans;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    string s;
    cin >> s;
    string res = cc.longestPalindrome(s);
    cout << res << endl;

    return 0;
}