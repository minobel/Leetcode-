class Solution {
    public:
        int sum_less_equal_to_k(vector<int>& nums, int goal) {
            if(goal < 0) return 0; //For Edge Case
            int sum = 0; int l = 0;
            int count = 0;
            for( int r = 0; r < nums.size(); r++){
                sum = sum + nums[r];
                while(sum > goal){
                    sum = sum - nums[l];
                    l++;
                }
                count = count + (r - l + 1);
            }
            return count;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal){
            return sum_less_equal_to_k(nums, goal) - sum_less_equal_to_k(nums, goal - 1);
        }
    };