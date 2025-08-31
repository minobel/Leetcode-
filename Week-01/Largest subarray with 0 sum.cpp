class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int>hash_map;
        int sum = 0;
        int len = 0;
        for( int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == 0){
                hash_map[sum] = -1;
            }
            if(hash_map.find(sum) != hash_map.end()){
                len = max(len, i - hash_map[sum]);
            }
            else hash_map[sum] = i;
        }
        return len;
    }
};