class Solution {
public:
    int reverse(int x) {
        int reverseNumber = 0;
        int sign = x > 0 ? 1 : -1;
        x = x * sign;
        while(x > 0) {
            if(reverseNumber > INT_MAX / 10) return reverseNumber = 0;
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }
        reverseNumber *= sign;
        return reverseNumber;
    }
};