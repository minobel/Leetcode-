//Kth Largest Element in an Array
class Solution {
public:
int partition( vector<int> &nums, int l, int r){
    int pivot = nums[r];
    int i = l - 1 ;
    for( int j = l; j < nums.size(); j++){
        if(nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap( nums[i+1] , nums[r]);
    return i + 1;
}
void partial_partition(vector<int> &nums, int k){
    random_shuffle( nums.begin() , nums.end());
    int l = 0; int r = nums.size() - 1;
    int threshold = 2*log2(nums.size());
    while( l < r && threshold--){
       int pivot =  partition(nums,l,r);
        if( pivot < k){
            l = pivot + 1;
        }
        else if( pivot > k){
            r = pivot - 1;
        }
        else break;
    }
}
    int findKthSmallest(vector<int>& nums, int k) {
        partial_partition( nums , k);
        return nums[k];
    }
     int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest( nums , nums.size() - k);
    }
};
