#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int get_index(int index, int delta, int piort) {
        if(index >= delta) return index - delta;
        else return piort + index;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        int len = nums.size();
        int piort = nums[0];
        int l = 0, r = len - 1;
        int mid;
        
        while(l < r) {
            mid = (l + r) >> 1;
            if(nums[mid] >= piort) l = mid + 1;
            else r = mid;
        }
        if(nums[len-1] > piort) l = 0;
        piort = l;
        l = 0, r = len - 1;
        int delta = len - piort;
        while(l <= r) {
            mid = (l + r) >> 1;
            int x = nums[get_index(mid, delta, piort)];
            if(x < target) l = mid + 1;
            else if(x == target) return get_index(mid, delta, piort);
            else r = mid - 1;
        }
        
        return -1;
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    int n, tar;
    vector<int> nums;
    cin >> n >> tar;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << cc.search(nums, tar) << endl;
    
    return 0;
    
}