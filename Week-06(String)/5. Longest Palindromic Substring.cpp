class Solution {
public:
    // Function to expand around the given center (l, r) and return palindrome length
    int expand_around_center(string s, int l, int r){
        int len = 0; // initialize length of palindrome
        // expand while characters match and indices are valid
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            len = r - l + 1; // update length of current palindrome
            l--; // move left pointer to left
            r++; // move right pointer to right
        }
        return len; // return the maximum length found from this center
    }

    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        if(s.empty()) return ""; // empty string check

        int start = 0; // start index of longest palindrome
        int end = 0;   // end index of longest palindrome

        // iterate over each character as potential center
        for(int i = 0; i < s.size(); i++){
            int odd = expand_around_center(s, i, i);      // odd length palindrome (single character center)
            int even = expand_around_center(s, i, i + 1); // even length palindrome (two character center)
            int max_len = max(even, odd); // maximum length from this center

            // if this palindrome is longer than previous longest
            if(max_len > end - start){
                start = i - (max_len - 1) / 2; // calculate start index( i - left half length)
                end   = i + max_len / 2;       // calculate end index (i + right half length)
            }
        }

        return s.substr(start, end - start + 1); // return longest palindrome substring
    }
};
