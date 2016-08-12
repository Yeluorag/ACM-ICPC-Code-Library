#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        map<string, int> checkUnique;

        int len = nums.size();
        for(int a = 0; a < len; a ++) {
            for(int d = len - 1; d > a; d --) {
                for(int b = a + 1, c = d - 1; b < c;) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[a]), tmp.push_back(nums[b]);
                        tmp.push_back(nums[c]), tmp.push_back(nums[d]);
                        string str = "";
                        for(int i = 0; i < 4; i ++) {
                        	if(tmp[i] < 0) str += "-";
                        	char c = tmp[i] + '0';
                        	str += c;
                        }
                        if(checkUnique.count(str) == 0){
                        	checkUnique[str] = 1;
                        	ret.push_back(tmp);
                        } 
                        b ++, c --;
                    } else if(sum > target) {
                        c --;
                    } else {
                        b ++;
                    }
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
    int n, t;
    cin >> n;
    cin >> t;
    vector<int> vec;
    int x;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        vec.push_back(x);
    }
    vector<vector<int> > ans = cc.fourSum(vec, t);
    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < 4; j ++) printf("%d, ", ans[i][j]);
        puts("");
    }
    
    return 0;
    
}