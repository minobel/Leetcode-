//TC - O(N)
//SC - O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentOnes = 0, tempOnes = 0;
        int maxOnes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentOnes++;
                tempOnes = currentOnes;
            }
            if (nums[i] != 1) {
                currentOnes = 0;
            }
            maxOnes = max(maxOnes, tempOnes);
        }
        return maxOnes;
    }
};