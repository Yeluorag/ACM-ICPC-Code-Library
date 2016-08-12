#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int val[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string roma[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string convertString = "";

		for(int i = 0; i < 13; i ++) {
			while(num >= val[i]) {	
				convertString += roma[i];
				num -= val[i];
			}
		}

		return convertString;
	} 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	int num;
	cin >> num;
	string ans = cc.intToRoman(num);
	cout << ans << endl;

	return 0;

}