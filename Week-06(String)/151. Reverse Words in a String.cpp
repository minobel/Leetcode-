class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // full string reverse

        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                // word [start, i-1] reverse manually
                int l = start, r = i - 1;
                while (l < r)
                    swap(s[l++], s[r--]);
                start = i + 1;
            }
        }
        int fst_space = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                fst_space = i;
                break;
            }
        }
        s.erase(0, fst_space);
        int lst_space = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                lst_space = i;
                break;
            }
        }
        s.erase(lst_space + 1, s.size() - 1);
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ' and s[i - 1] == ' ') {
                s.erase(s.begin() + i);
            } else
                i++;
        }
        return s;
    }
};