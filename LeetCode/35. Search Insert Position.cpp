class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
        	return 0;
        vector<int>::iterator ite;
        ite = lower_bound(nums.begin(), nums.end(), target);
        return ite - nums.begin();
    }
};