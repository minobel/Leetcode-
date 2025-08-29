class Solution {
public:
    // Function to calculate how many numbers are missing <= mid
    int missing(vector<int>& arr, int mid) {
        // upper_bound returns iterator to first element > mid
        // Subtract arr.begin() to get count of elements <= mid
        int cnt = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        // Missing numbers = total numbers till mid - numbers present in arr
        return mid - cnt;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int l = 1;                  // Start of search range
        int h = arr.back() + k;      // Safe upper bound for k-th missing number
        int ans;                     // To store intermediate answer

        while (l <= h) {
            int mid = (l + h) / 2;   // Middle of current range
            // Check how many numbers are missing up to mid
            if (missing(arr, mid) >= k) {
                ans = mid;           // mid could be the answer
                h = mid - 1;         // Search left half
            } else {
                l = mid + 1;         // Search right half
            }
        }

        return ans;  // Final answer: k-th missing positive number
    }
};
