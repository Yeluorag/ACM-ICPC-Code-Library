#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

class Solution {
public:
	bool match(char x, char y) {
		return (x == '(' && y == ')') || 
				(x == '[' && y == ']') ||
				(x == '{' && y == '}');
	}
	bool isValid(string s) {
        int len = s.length();
        stack<char> stk;
        for(int i = 0; i < len; i ++) {
        	if(!stk.empty()) {
        		if(match(stk.top(), s[i])) stk.pop();
        		else stk.push(s[i]);
           	} else stk.push(s[i]);
        }
        return stk.empty();
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