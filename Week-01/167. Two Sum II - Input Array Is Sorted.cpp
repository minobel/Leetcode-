// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int idx1, idx2;
        while( i < j ){
            int sum = numbers[i] + numbers[j];
            if(sum > target){
                j--;
            }
            else if(sum < target) i++;
            else{
               idx1 = i + 1; idx2 = j + 1;
               break;
            }
        }
        return {idx1,idx2};
    }
};