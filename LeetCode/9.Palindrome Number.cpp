#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		string s = "";
		if(x < 0) return false;
		while(x != 0) {
			s += x % 10;
			x /= 10;
		}
		int lengthOfString = s.length();
		for(int i = 0; i < (lengthOfString >> 1); i ++) {
			if(s[i] != s[lengthOfString - i - 1]) return false;
		}
		return true;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;


	return 0;

}