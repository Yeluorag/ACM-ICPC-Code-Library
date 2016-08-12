#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
        int convertNumber = 0;
        int len = s.length();
        map<char, int> rti;
        rti['M'] = 1000, rti['D'] = 500, rti['C'] = 100, 
        rti['L'] = 50, rti['X'] = 10, rti['V'] = 5, rti['I'] = 1;
        for(int i = 0; i < len; i ++) {
        	if(i < len - 1 && rti[s[i+1]] > rti[s[i]]) {
        		convertNumber += rti[s[i+1]] - rti[s[i]];
        		i ++;
        	} else convertNumber+= rti[s[i]];
        }
        return convertNumber;
    } 
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	Solution cc;
	string s;
	cin >> s;
	cout << cc.romanToInt(s) << endl;

	return 0;

}