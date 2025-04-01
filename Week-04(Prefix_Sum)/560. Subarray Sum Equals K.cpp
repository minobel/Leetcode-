//TC - O(N)
/* Concept - Just store Sum as a Presum, then Calculate sum - k. In map key is PreSum and value is Presum Count
If we get sum - k in our map that means we got a Valid Sub Array. Then we increase Count. Also increase Presum Count*/
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int count = 0;
            unordered_map<int, int> hash_map;
            int prefix_sum = 0;
            hash_map[0] = 1; //Cause if we Got Sum - k = 0, that means we have one valid Subarray, For Example arr[] = {3, -3, 1, 1, 1} , here if we calculate remove for last element of this array and its 0 also its a Valid.        
             for (int num : nums) {
                prefix_sum += num;
                count += hash_map[prefix_sum - k];
                hash_map[prefix_sum]++;
            }
            return count;
        }
    };