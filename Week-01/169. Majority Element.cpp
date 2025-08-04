
 //Moore's Voting Algorithm
 //TC - O(N)
 //SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (element == nums[i]) {
                count++;
            } else
                count--;
            if (count == 0) {
                element = nums[i + 1];
            }
        }
        return element;
    }
};
