class Solution {
public:
    int count_days(vector<int>& weights, int mid) {
        int curr_weight = 0;
        int days = 0;
        for (int i = 0; i < weights.size(); i++) {
            curr_weight += weights[i];
            if (curr_weight > mid) {
                days++;
                curr_weight = weights[i];
            }
        }
        return days + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        int l = *max_element(weights.begin(), weights.end());
        int h = sum;
        int ans;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (count_days(weights, mid) <= days) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};