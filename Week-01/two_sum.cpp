class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int, int> set_num;
        int vector_size = nums.size();
        for( int j = 0; j < vector_size; j++){
            int num_1 = target - nums[j];
            if(set_num.count(num_1)){
                return {set_num[num_1], j};
            } 
            set_num[nums[j]] = j;
        }
        return {};
    }

};
