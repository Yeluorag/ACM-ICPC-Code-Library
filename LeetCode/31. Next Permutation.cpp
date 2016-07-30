#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		bool ok = false;
		for(int i = len - 2; i >= 0; i --) {
			if(nums[i+1] > nums[i]) {
				for(int j = i + 1; j <= (i + len) / 2; j ++) swap(nums[j], nums[len+i-j]);
				for(int j = i + 1; j < len; j ++) if(nums[j] > nums[i]) {
					swap(nums[i], nums[j]);
					break;
				}
				ok = true;
				break;
			} 
		}
		if(!ok) for(int i = 0; i < len / 2; i ++) swap(nums[i], nums[len-i-1]);
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
    cc.nextPermutation(vec);
    for(int i = 0; i < n; i ++) {
        cout << vec[i] << " ";
    } puts("");

	return 0;

}