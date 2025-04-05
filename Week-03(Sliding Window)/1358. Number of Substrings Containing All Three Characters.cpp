//T.C. - O(N)
/*
Concept – We know that once we find the first valid substring, 
we can generate additional valid substrings by extending it. 
Let’s look at an example: suppose the string is "b, b, a, c". 
Here, we can find two valid substrings that contain all three characters.
How can we identify them?
We track the **minimum index** among the latest positions of 'a', 'b', and 'c'. 
Then, we add 1 to this minimum index. 
In this case, the smallest valid substring is "b, a, c", 
and the minimum index among these is 1. So, (1 + 1) = 2. 
That means we can form 2 valid substrings ending at this point.
*/

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int hash[3] = {-1,-1,-1};
            int count = 0;
            for( int i = 0; i < s.size(); i++){
                hash[s[i] - 'a'] = i;
                if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                    count = count + (1 + min(hash[0], min(hash[1], hash[2])));//The +1 comes from the fact that indices are zero-based
                }
            }
            return count;
        }
    };