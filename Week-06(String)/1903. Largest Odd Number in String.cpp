class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size();
        int end = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' or s[i] == '3' or s[i] == '5' or s[i] == '7' or
                s[i] == '9') {
                end = i;
                break;
            }
        }
        if (end == -1)
            return "";
        return s.substr(0, end + 1);
    }
};