#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> findRange;
        int left = -1, right = -1;
        int len = nums.size();
        int l = 0, r = len - 1, mid;
        
        while(l < r) {
            mid = (l + r) >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        left = l;
        
        l = 0, r = len - 1;
        while(l < r) {
            mid = (l + r) >> 1;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        right = r;
        
        if(nums[right] != target) right --;
        if(nums[left] != target) left = right = -1;
        
        findRange.push_back(left);
        findRange.push_back(right);
        return findRange;
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    int n, x, tar;
    vector<int> vec;
    cin >> n >> tar;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        vec.push_back(x);
    }
    vec = cc.searchRange(vec, tar);
    cout << vec[0] << vec[1] << endl;
    
    
    return 0;
    
}