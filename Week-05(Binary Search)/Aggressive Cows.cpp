class Solution {
  public:
    int cows(vector<int> &stalls, int mid){
        int last_stall = stalls[0];
        int cows = 1;
        for( int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last_stall >= mid){
                cows++;
                last_stall = stalls[i];
            }
        }
        return cows;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = stalls.back();
        int ans;
        while(l <= h){
            int mid = (l + h)/2;
            if(cows(stalls, mid) >= k){
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return ans;
    }
};