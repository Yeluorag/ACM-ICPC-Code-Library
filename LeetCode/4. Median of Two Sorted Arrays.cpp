#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, m;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m, n;
        const int INF = 0x3f3f3f3f;
        m = nums1.size(), n = nums2.size();
        vector<double> ret;
        int i = 0, j = 0;
        double ans = INF;
        while(i < m || j < n) {
        	bool f1 = nums1.empty(), f2 = nums2.empty();
        	if(f1 && !f2) ret.push_back(nums1[j++]);
        	else if(f2 && !f1) ret.push_back(nums2[j++]);
        	else if(f1 && f2) break;
        	else {
	            if(i >= m || (i < m && nums1[i] >= nums2[j]))
	                ret.push_back(nums2[j++]);
	            else if(j >= n || (j < n && nums1[i] <= nums2[j]))
	                ret.push_back(nums1[i++]);
        	}
        }
        int sz = ret.size();
        printf("--%d\n", sz);
        if((n + m) & 1) ans = ret[sz/2];
        else ans = (ret[sz/2] + ret[sz/2+1]) / 2;
        return ans;
    }
};
class Solution {
public:
    double findKth(vector<int>& a, int aBeg, int aEnd, vector<int>& b, int bBeg, int bEnd, int k) {
        if(aEnd < aBeg) return b[k-1];
        if(bEnd < bBeg) return a[k-1];

        int aMid = aBeg + (aEnd - aBeg) / 2;
        int bMid = bBeg + (bEnd - bBeg) / 2;
        int cnt = (aMid - aBeg + 1) + (bMid - bBeg + 1); 

        if(a[aMid] > b[bMid]) {
            if(cnt >= k) return findKth(a, aBeg, aMid - 1, b, bBeg, bEnd, k);
            else return findKth(a, aBeg, aEnd, b, bMid + 1, bEnd, k - (bMid - bBeg + 1));
        } else {
            if(cnt >= k) return findKth(a, aBeg, aEnd, b, bBeg, bMid - 1, k);
            else return findKth(a, aMid + 1, aEnd, b, bBeg, bEnd, k - (aMid - aBeg + 1));
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m, n;
        const int INF = 0x3f3f3f3f;
        m = nums1.size(), n = nums2.size();
        if((m + n) & 1) 
            return findKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n + 1) / 2);
        else 
            return (findKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2) + 
            findKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2 + 1)) / 2;
    } 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    vector<int> v1, v2;
    scanf("%d %d", &n, &m);
    int x;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x);
        v1.push_back(x);
    } sort(v1.begin(), v1.end());
    for(int i = 0; i < m; i ++) {
        scanf("%d", &x);
        v2.push_back(x);
    } sort(v2.begin(), v2.end());
    Solution cc;
    double ans = cc.findMedianSortedArrays(v1, v2);
    cout << ans << endl;
    
}