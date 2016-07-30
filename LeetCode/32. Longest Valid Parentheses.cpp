#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    bool match(char x, char y) {
        return x == '(' && y == ')';
    }
    struct node {
        char c;
        int index;
        node(char cc, int ii) : c(cc), index(ii) {}
    };

    int longestValidParentheses(string s) {
        int len = s.length();
        int* parenthesesLength = (int*)malloc(sizeof(int) * len);
        bool* matchString = (bool*)malloc(sizeof(bool) * len);
        for(int i = 0; i < len; i ++) {
        	parenthesesLength[i] = 0;
        	matchString[i] = false;
        }
        stack<node> stk;
        
        int max_len = 0;
        for(int i = 0; i < len; i ++) {
            node tmp(s[i], i);
            if(stk.empty()) {
                stk.push(tmp);
            } else {
                if(match(stk.top().c, s[i])) {
                    
                    int cnt = 2;
                    if(matchString[i - 1]) {
                       cnt += parenthesesLength[i - 1];
                    }
                    if((stk.top().index - 1 >= 0) && matchString[stk.top().index-1]) {
                        cnt += parenthesesLength[stk.top().index-1];
                    }
                    matchString[i] = matchString[stk.top().index] = true;
                    parenthesesLength[stk.top().index] = parenthesesLength[i] = cnt;
                    stk.pop();
                } else {
                    stk.push(tmp);
                }
            }
            max_len = max(max_len, parenthesesLength[i]);
        }
        free(parenthesesLength);
        free(matchString);
        
        return max_len;
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
	cout << cc.longestValidParentheses(s) << endl;

	return 0;

}