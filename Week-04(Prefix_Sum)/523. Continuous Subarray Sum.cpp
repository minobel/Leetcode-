//TC - O(N)
//SC - O(N)
//দুইটা prefix_sum এর remainder same হলে, তাদের মধ্যকার subarray divisible by k হবে।
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rem_idx;
        rem_idx[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (rem_idx.find(sum % k) == rem_idx.end()) {
                rem_idx[sum % k] = i;
            }
            if (rem_idx.find(sum % k) != rem_idx.end() &&
                (i - rem_idx[sum % k]) >= 2) {
                return true;
            }
        }
        return false;
    }
};