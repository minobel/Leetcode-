//TC - O(N)
//SC - O(K)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count_freq;
        int sum = 0, count = 0;
        count_freq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
/* Logic :ধরো তোমার একটা 5 ঘন্টার ঘড়ি আছে — এর ঘরগুলো হল:
0 → 1 → 2 → 3 → 4 → 0 → ...
 এখন যদি তুমি 0 থেকে পিছনের দিকে 1 ঘন্টা যাও, তুমি কোথায় থাকবে?
➡️ 0 - 1 = -1
কিন্তু ঘড়িতে -1 তো নেই, তাই তুমি ঘড়ি ঘুরে 4-এ যাবে!
💡 ঠিক যেমন ঘড়িতে 12 টা থেকে 1 ঘন্টা পেছালে 11 বাজে। তেমনি 0 থেকে পেছালে 4 বাজে।
*/
            if (count_freq.find(rem) != count_freq.end()) {
                count += count_freq[rem];
            }
            count_freq[rem]++;
        }
        return count;
    }
};