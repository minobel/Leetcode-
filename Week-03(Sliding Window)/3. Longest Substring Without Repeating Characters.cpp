             //Time Complexity: O(n)
            //Space Complexity: O(n)
/*
Concept: Right pointer (r) moves through each character in the string, updating the map with the most recent index of the character.

Left pointer (l) moves when a duplicate character is encountered within the current window, ensuring the substring remains unique. 
If a duplicate is found, l is moved to the index right after the last occurrence of that character.

The length of the current valid window is calculated as r - l + 1, and the maximum length is updated accordingly.
*/
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0, max_len = 0;
            unordered_map<char, int> mpp;
            for( int r = 0; r < s.size(); r++){
                if( mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                   l =  mpp[s[r]] + 1;
                }
                mpp[s[r]] = r;
                max_len = max(max_len, r - l + 1);
            }
            return max_len;
        }
    };

   /* Example for "abcabcbb"
    Start at r = 0 (char = 'a')
→ Not seen before. Add to map.
→ max_len = 1, window = "a"

r = 1 (char = 'b')
→ Not seen. Add to map.
→ max_len = 2, window = "ab"

r = 2 (char = 'c')
→ Not seen. Add to map.
→ max_len = 3, window = "abc"

r = 3 (char = 'a')
→ Seen at index 0, which is within the window (since l = 0)
→ Move l = 1, update map
→ Window becomes "bca", max_len = 3

r = 4 (char = 'b')
→ Seen at 1 ≥ l → move l = 2
→ Window: "cab", max_len = 3

r = 5 (char = 'c')
→ Seen at 2 ≥ l → move l = 3
→ Window: "abc", still 3

r = 6 (char = 'b')
→ Seen at 4 ≥ l → move l = 5
→ Window: "cb", still 3

r = 7 (char = 'b')
→ Seen at 6 ≥ l → move l = 7
→ Window: "b", still 3
*/