#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#include <cmath>
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
        int ret = INT_MAX, cnt = INT_MAX;
        int sz = nums.size();

        for(int i = 0; i < sz; i ++) {

        	if(cnt == 0) break;
        	int last = INT_MAX;
        	for(int j = i + 1, k = sz - 1; j < sz && k > j;) {
        		int sum = nums[i] + nums[j] + nums[k];
        		int dis = abs(sum - target);
        		if(dis > last) break;
        		if(sum == target) {
        			ret = sum;
        			cnt = 0;
        			break;
        		} else if(sum > target) {
        			if(dis < cnt) {
        				ret = sum;
        				cnt = dis;
        			}
        			k --;
        		} else {
        			if(dis < cnt) {
        				ret = sum;
        				cnt = dis;
        			}
        			j ++;
        			
        		}
        		last = dis;
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
	int n, target;
	cin >> n >> target;
	vector<int> vec;
	int x;
	for(int i = 0; i < n; i ++) {
		cin >> x;
		vec.push_back(x);
	}
	cout << cc.threeSumClosest(vec, target) << endl;

	return 0;

}