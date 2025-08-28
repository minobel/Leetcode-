class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;int mid;
        while(l < h){
            mid = (l + h)/2;
            if(nums[h] > nums[mid]){
                h = mid;
            }
            else
            l = mid + 1;
        }
        return nums[l];
    }
};