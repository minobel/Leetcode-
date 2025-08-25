class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;

        // যতক্ষণ পর্যন্ত search space এ একটার বেশি element আছে
        while (l < h) {
            int mid = (l + h) / 2;

            // mid কে সবসময় even index এ নিয়ে আসা
            // কারণ pair সবসময় even index থেকে শুরু হয়
            if (mid % 2 == 1) mid--;

            // যদি mid আর mid+1 সমান হয় → মানে এই জোড়া ঠিক আছে
            // সেক্ষেত্রে single element ডানদিকে আছে
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;  // বাম দিক বাদ দাও
            }
            // নাহলে pair ভেঙেছে → single element বাম দিকে বা mid এ
            else {
                h = mid;      // ডান দিক বাদ দাও
            }
        }

        // যখন l == h হয়ে যাবে, তখন search space এ মাত্র একটিই element থাকবে
        // ওটাই single element
        return nums[l];
    }
};
