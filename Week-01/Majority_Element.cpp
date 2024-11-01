//Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int element;
        for( int i = 0; i < n; i++){
            if( count == 0){
                count = 1;
                element = nums[i];
            }
            else if(element == nums[i]){
                count++;
            }
            else
            count--;
        }
        int  count_for_checking = 0;
        for( int i = 0; i < n; i++){
            if( nums[i] == element )
            count_for_checking++;
        }
        if( count_for_checking > n/2){
            return element;
        }
        return {};
}
};
