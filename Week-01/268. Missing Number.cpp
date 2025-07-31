//Better Solution
//TC - O(N)
//SC - O(N)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.resize(nums.size() * 2 , -1);
        for( int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[n] = 0;
            }
            else if(nums[i] == n){
                nums[(2 * n) - 1] = n;
            }
            else
            nums[(nums[i]) + n] =  nums[i];
        }
        for(int i = 0; i < n; i++){
            nums[i] = nums[i + n];
        }
        nums.resize(n);
        int mis_num;
        for( int i = 0; i <= n; i++){
            if(nums[i] != i){
                mis_num = i;
                break;
            }
        }
        return mis_num;
    }
};

//Optimal Solution 1
//TC - O(N)
//SC - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n * ( n + 1 )) / 2;
        int cur_sum = 0;
        for( int i = 0; i < n; i++){
            cur_sum += nums[i];
        }
        return total_sum - cur_sum;
    }
};

//Optimal Solution 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_xor = 0, cur_xor = 0;
        for( int i = 0; i <= nums.size(); i++){
            total_xor ^= i;
        }
        for( int i = 0; i < nums.size(); i++){
            cur_xor ^= nums[i];
        }
        return total_xor ^ cur_xor;
    }
};