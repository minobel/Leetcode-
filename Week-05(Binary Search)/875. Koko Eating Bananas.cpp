class Solution {
public:
    long long total_hour(vector<int>& piles, int mid) {
        long long sum = 0;
        for (long long i = 0; i < piles.size(); i++) {
            sum = sum + (piles[i] + mid - 1) / mid;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int min_ans = INT_MAX;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (total_hour(piles, mid) <= h) {
                min_ans = min(min_ans, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return min_ans;
    }
};