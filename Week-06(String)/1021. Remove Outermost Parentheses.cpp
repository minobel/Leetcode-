class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string valid_s = "";
        for( int i = 0; i < s.size(); i++){
            if(s[i] == ')') count--;
            if(count != 0) valid_s.push_back(s[i]);
            if(s[i] == '(') count++;
        }
        return valid_s;
    }
};