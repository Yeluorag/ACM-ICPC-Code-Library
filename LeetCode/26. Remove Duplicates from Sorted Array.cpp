#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty()) return 0;

		int lastElement = nums[0];
		vector<int>::iterator ite = nums.begin();
		ite ++;
		for(; ite != nums.end();) {
			if(*ite == lastElement) nums.erase(ite);
			else lastElement = *ite, ite ++;
		}
		return nums.size();
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
	int x, n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		vec.push_back(x);
	}
	int ans = cc.removeDuplicates(vec);
	for(int i = 0; i < ans; i ++) cout << vec[i] << " "; puts("");

	return 0;

}