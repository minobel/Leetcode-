class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int j = nums.size() - 1;
    int i = nums.size() - 1;
    int count = 0;
    int total = nums.size();
    while(i > 0 and j > 0){
        if( nums[i] == nums[j - 1]){
            nums.erase(nums.begin() + i);
            count++;
        }
        j--;i--;
    }
        return total - count;
    }
};

//Another Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i = nums.size() - 1;
    while(i > 0) {
        if(nums[i] == nums[i-1]){
            nums.erase(nums.begin() + i);
        }
        i--;
    }
    return nums.size();

    }
};