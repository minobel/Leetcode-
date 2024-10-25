class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int, int> set_num;
        int vector_size = nums.size();
        for( int i = 0; i < vector_size; i++){
            int num_1 = target - nums[i];
            if(set_num.count(num_1)){
                return {set_num[num_1], i};
            } 
            set_num[nums[i]] = i;
        }
        return {};
    }

};
