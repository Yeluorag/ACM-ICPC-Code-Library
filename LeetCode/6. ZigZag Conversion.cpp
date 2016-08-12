class Solution {
public:
    string convert(string s, int numRows) {
        string ansString = "";
        int length = s.length();
        bool midHasChar = false;
        int distanceOfChar = (numRows - 1) << 1;
        if(numRows == 1) distanceOfChar = 1;
        for(int i = 0; i < numRows; i ++) {
            int index = i, mid;
            midHasChar = (i > 0 && i < numRows - 1);
            if(midHasChar) mid = index +  2 * (numRows - i - 1);
            while(index < length) {
                ansString += s[index];
                index += distanceOfChar;
                if(midHasChar && mid < length) {
                    ansString += s[mid];
                    mid += distanceOfChar;
                }
            }
        }
        return ansString;
    }
};