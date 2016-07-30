#include <cctype>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign, length = str.length(), begin = 0;
        if(!length) return 0;
        
        for(begin = 0; begin < length; begin ++) {
            if(isspace(str[begin])) continue;
            else break;
        }
        if(str[begin] == '+' || isdigit(str[begin])) sign = 1;
        else if(str[begin] == '-') sign = -1;
        else return 0;
        
        int retNumber = 0;
        if(str[begin] == '+' || str[begin] == '-') begin ++;
        for(int i = begin; i < length; i ++) {
            if(isdigit(str[i])) { 
                if(retNumber > INT_MAX / 10 || (retNumber == INT_MAX / 10 && str[i] > '7'))
                    return INT_MAX;
                if(retNumber < INT_MIN / 10 || (retNumber == INT_MIN / 10 && str[i] > '8'))
                    return INT_MIN;
                
                retNumber = retNumber * 10 + sign * (str[i] - '0');
            }
            else break;
        }
        return retNumber;
    }
};

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //    freopen("/Users/apple/out.txt","w",stdout);
#endif
    Solution cc;
    string s;
    cin >> s;
    int ret = cc.myAtoi(s);
    cout << ret << endl;


    return 0;

}