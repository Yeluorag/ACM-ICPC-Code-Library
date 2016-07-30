#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int l = 0, r = n - 1;
		int h = std::min(height[l], height[r]);
		int area = 0;
		while(l < r) {
			area = std::max(area, std::min(height[l], height[r]) * (r - l));
			if(height[l] < height[r]) l ++;
			else r --;
		}
		return area;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	int n;
	cin >> n;
	vector<int> vec;
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	cout << cc.maxArea(vec) << endl;

	return 0;

}