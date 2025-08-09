//TC - O(n)
//SC - O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for( int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                idx = i;
                break;
            }
        }
        if(idx == - 1)  return reverse(nums.begin(), nums.end());
        for( int i = n - 1; i >= 0; i--){
            if(nums[idx] < nums[i]){
                swap(nums[idx], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + (idx + 1), nums.end());
    }
};