class Solution {
  public:
    int pages(vector<int> &arr, int mid){
        int sum = 0;
        int students = 1;
        for( int i = 0; i < arr.size(); i++){
            sum = sum + arr[i];
            if(sum > mid ){
                students++;
                sum = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size() < k) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int sum = 0;
        for( int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }
        int h = sum;
        int ans;
        while(l <= h){
            int mid = (l + h)/2;
            if(pages(arr,mid) <= k){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};