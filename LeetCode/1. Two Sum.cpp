class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret(2, -1);
		unordered_map<int, int> mp;
		int sz = nums.size();
		for(int i = 0; i < sz; ++ i) {
			if(mp.find(target - nums[i]) == mp.end()) {
				mp[nums[i]] = i;
			} else {
				ret[0] = mp[target - nums[i]];
				ret[1] = i;
				return ret;
			}
		}
	}
};
