#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int sz = strs.size();
		if(sz == 0) return "";
		string str = strs[0];
		int len1 = str.length();
		int bound = len1;
		for(int i = 1; i < sz; i ++) {
			int len2 = strs[i].length();
			int j = 0;
			for(j = 0; j < bound && j < len2; j ++) {
				if(str[j] != strs[i][j]) {
					break;
				}
			}
			bound = j;
		}

		string prefixString = "";
		for(int i = 0; i < bound; i ++) prefixString += str[i];
		return prefixString; 
 	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	string a, b, c;
	cin >> a;
	cin >> b;
	// cin >> c;
	vector<string> vec;
	vec.push_back(a);
	vec.push_back(b);
	// vec.push_back(c);
	cout << cc.longestCommonPrefix(vec) << endl;

	return 0;

}