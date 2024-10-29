class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>nums_set;
        for(int u:nums){
         nums_set.insert(u);
        }
        int max_count = 0;
        for(int ele:nums){
            if( nums_set.find(ele - 1) == nums_set.end()){
                int count = 0;
                while(nums_set.find(ele++) != nums_set.end()){
                    count++;
                }
                 max_count = max(max_count , count);
            }
        }
                return max_count;
    }
};
