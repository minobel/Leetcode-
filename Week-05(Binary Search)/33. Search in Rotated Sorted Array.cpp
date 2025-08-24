class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;                      // left pointer
        int h = nums.size() - 1;        // right pointer
        int ans = -1;                   // যদি না পাই তবে -1 return করব

        while (l <= h) {
            int mid = (l + h) / 2;      // middle index বের করলাম

            if (nums[mid] == target)    // ✅ যদি target mid এ মিলে যায়
                return mid;             // index return করে দাও

            // 👉 যদি left side unsorted হয় (মানে nums[l] > nums[mid])
            else if (nums[l] > nums[mid]) {
                // তাহলে right half টা sorted
                // check করি target কি এই sorted অংশের মধ্যে আছে কিনা
                if (nums[mid] <= target && target <= nums[h]) {
                    l = mid + 1;        // target right half এ → search ডান দিকে
                }
                else {
                    h = mid - 1;        // target right half এ নাই → search বাম দিকে
                }
            }

            // 👉 অন্যথায় (nums[l] <= nums[mid]) → left half sorted
            else {
                // check করি target কি এই left half এর মধ্যে আছে কিনা
                if (nums[l] <= target && target <= nums[mid]) {
                    h = mid - 1;        // target left half এ → search বাম দিকে
                }
                else {
                    l = mid + 1;        // target left half এ নাই → search ডান দিকে
                }
            }
        }

        return ans;  // target না পেলে -1 return হবে
    }
};
