class Solution {
public:
    int divisor_sum(vector<int>& nums, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + mid - 1) / mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_ele = *max_element(nums.begin(), nums.end());
        int l = 1;
        int h = max_ele;
        int nearest_int;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (divisor_sum(nums, mid) <= threshold) {
                nearest_int = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return nearest_int;
    }
};