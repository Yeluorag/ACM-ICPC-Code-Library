#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<string>& vec, string s, int leftCnt, int rightCnt, int n) {
		if(s.length() == 2 * n) {
			vec.push_back(s);
			return;
		}
		if(leftCnt < n) {
			string nextString = s + '(';
			dfs(vec, nextString, leftCnt + 1, rightCnt, n);
		}
		if(leftCnt > rightCnt) {
			string nextString = s + ')';
			dfs(vec, nextString, leftCnt, rightCnt + 1, n);
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		dfs(ret, "", 0, 0, n);

		return ret;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	int n;
	cin >> n;
	vector<string> ans = cc.generateParenthesis(n);
	for(int i = 0; i < ans.size(); i ++) {
		cout << ans[i] << endl;
	}

	return 0;

}