class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort( nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for( int i = 0; i < n; i++){
            int c = nums[i];
            int l = i + 1;
            int r = n - 1;
            while( i + 1 < n && nums[i + 1] == c) i++;
            while(l < r){
                int sum = -(nums[l] + nums[r]);
                if( sum < c){
                    r--;
                }
                else if(sum > c) l++;
                else
                {
                    while( l + 1 < r && nums[l + 1] == nums[l]) l++;
                    while(r - 1 > l && nums[r - 1] == nums[r]) r--;
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                } 
            }
        }
        return ans;
        
    }
};
