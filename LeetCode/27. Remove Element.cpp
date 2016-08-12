#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator ite;
		for(ite = nums.begin(); ite != nums.end(); ) {
			if(*ite == val) nums.erase(ite);
			else ite ++
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


	return 0;

}