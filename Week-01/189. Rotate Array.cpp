// TC = O(N)
// SC = O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        nums.resize(n+k);
        for( int i = n; i < n + k; i++){
            nums[i] = 0;
        }
        for( int i = n - 1; i >= 0; i--){
        nums[i + k] = nums[i];
        }
        for( int i = 0; i < k; i++){
        nums[i] = nums[n + i];
         }
        nums.resize(n);
    }
};