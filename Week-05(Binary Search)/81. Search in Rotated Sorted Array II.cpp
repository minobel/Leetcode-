class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ans = false;               // শেষে true/false রিটার্ন হবে
        int l = 0;                      // left pointer
        int h = nums.size() - 1;        // right pointer

        while (l <= h) {

            // 👉 duplicate skip করার জন্য
            while (l < h && (nums[l] == nums[h])) {
                // যদি target এই duplicate এর সাথে মিলে যায়
                if (nums[l] == target || nums[h] == target) {
                    ans = true;
                    break;              // বের হয়ে যাই
                }
                l++;                    // left বাড়াও
                h--;                    // right কমাও
            }

            int mid = (l + h) / 2;      // mid বের করলাম

            if (nums[mid] == target) {  // ✅ যদি mid এ target মিলে যায়
                ans = true;
                break;
            }

            // 👉 check করি কোন half sorted
            else if (nums[l] > nums[mid]) {
                // Right half sorted
                if (nums[mid] <= target && target <= nums[h]) {
                    l = mid + 1;        // target ডানে আছে
                } else {
                    h = mid - 1;        // target বামে আছে
                }
            } else {
                // Left half sorted
                if (nums[l] <= target && target <= nums[mid]) {
                    h = mid - 1;        // target বামে আছে
                } else {
                    l = mid + 1;        // target ডানে আছে
                }
            }
        }

        if (ans) return true;           // পাওয়া গেলে true
        else return false;              // না পেলে false
    }
};
