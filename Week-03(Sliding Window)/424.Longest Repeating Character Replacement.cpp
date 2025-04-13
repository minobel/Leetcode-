             //Time Complexity: O(n)
            //Space Complexity: O(1)
/*
Concept: As we move the right pointer, we track the frequency of characters in the window.
To make all characters the same, we calculate how many characters need to be changed by:
    (window length - max frequency character).
If the number of changes is greater than k, we shrink the window from the left.
By doing this, we maintain a valid window and update the maximum valid length accordingly.
*/


class Solution {
    public:
        int characterReplacement(string s, int k) {
            int hash_map[26] = {0}; 
            int l = 0;           
            int max_len = 0;      
            int max_freq = 0;     
            for (int r = 0; r < s.size(); r++) {
                // Increment frequency of the current character
                hash_map[s[r] - 'A']++;
    
                // Update the max frequency in the current window
                max_freq = max(max_freq, hash_map[s[r] - 'A']);
    
                // Calculate how many characters we need to replace to make all characters same
                int changes = (r - l + 1) - max_freq;
    
                // If changes needed > k, the window is invalid; shrink it from the left
                if (changes > k) {
                    hash_map[s[l] - 'A']--;  // Remove the leftmost character
                    l++;                     // Shrink window
                }
    
                // Update max length if current window is valid
                max_len = max(max_len, r - l + 1);
            }
    
            return max_len;
        }
    };
    
    
    /*
     Example Walkthrough:
    Input: s = "AABABBA", k = 1
    
    Step-by-step:
    - Start with window [0,2] = "AAB" -> Replace 1 char => valid
    - Extend to [0,3] = "AABA" -> Replace 1 => valid
    - Extend to [0,4] = "AABAB" -> Replace 2 => invalid (k=1) -> Shrink from left
    - Final answer: max valid window length = 4
    
    */
    