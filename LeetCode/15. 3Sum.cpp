#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ret;
		map<string, int> unique;

		int sz = nums.size();
		sort(nums.begin(), nums.end());	
		for(int i = 0; i < sz; i ++) {
			if(i && nums[i] == nums[i-1]) continue;
			for(int j = i + 1, k = sz - 1; j < sz && k > j;) {
				vector<int> vec;
				int sum = nums[i] + nums[j] + nums[k];
				if(sum == 0) {
					vec.push_back(nums[i]);
					vec.push_back(nums[j]);
					vec.push_back(nums[k]);
					ret.push_back(vec);
					j ++, k --;
					while(nums[j] == nums[j-1] && nums[k] == nums[k+1]) 
						j++, k --;
				} else if(sum < 0) {
					j ++;
				} else {
					k --;
				}
			}
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
	vector<int> vec;
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		vec.push_back(x);
	}

	vector<vector<int> > ans = cc.threeSum(vec);
	for(int i = 0; i < ans.size(); i ++) {
		for(int j = 0; j < 3; j ++) {
			printf("%d, ", ans[i][j]);
		} puts("");
	}

	return 0;

}