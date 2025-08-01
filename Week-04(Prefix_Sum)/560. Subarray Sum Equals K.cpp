//TC - O(N)
/* Concept - Just store Sum as a Presum, then Calculate sum - k. In map key is PreSum and value is Presum Count
If we get sum - k in our map that means we got a Valid Sub Array. Then we increase Count. Also increase Presum Count*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map < int , int > pre_sum;
        pre_sum[0] = 1;
        int sum = 0;
        int count = 0;
        for( int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(pre_sum.find(sum - k) != pre_sum.end()){
                count += pre_sum[sum - k];
            } 
            pre_sum[sum]++;
        }
        return count;
    }
};