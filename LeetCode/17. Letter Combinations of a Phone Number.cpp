#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		string mp[10];
		mp[2] = "abc", mp[3] = "def", mp[4] = "ghi";
		mp[5] = "jkl", mp[6] = "mno", mp[7] = "pqrs";
		mp[8] = "tuv", mp[9] = "wxyz";
		int len = digits.length();
		if(len <= 0) return ret;
		string tmp = "";
		for(int i = 0; i < len; i ++) {
			tmp += mp[digits[i] - '0'][0];
		}
		ret.push_back(tmp);
		int index = len - 1;
		
		while(true) {
			bool ok = false;
			tmp[index] ++;
			while(true) {
				string str = mp[digits[index] - '0'];
				if(tmp[index] <= str[str.length() - 1]) break;

				tmp[index] = mp[digits[index] - '0'][0];
				index --;
				if(index < 0) { ok = true; break; }
				tmp[index] ++;
			}
			index = len - 1;
			if(ok) break;
			ret.push_back(tmp);
		}
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
	string str;
	cin >> str;
	vector<string> vec = cc.letterCombinations(str);
	for(int i = 0; i < vec.size(); i ++) {
		cout << vec[i] << endl;
	}

	return 0;

}