#include <map>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> mp;
		int len = s.length();
		int ans = 0, l = 0, r = -1;
		while(++ r < len) {
			if(mp.count(s[r]) == 0) {
				mp[s[r]] = r;
			} else {
				int k = mp[s[r]];
				while(l ++ < k) mp.erase(s[l-1]);
				mp[s[r]] = r;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}  
};
#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    string s;
    cin >> s;
    Solution cc;
    cout << cc.lengthOfLongestSubstring(s) << endl;
}