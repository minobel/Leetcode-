/*তোমার জন্য সংক্ষেপে **notes** আকারে নিচে দিলাম:

---

### 🔹 Problem:

Find the length of the **shortest subarray** having the same **degree** as the full array.

---

### 🔹 Key Concepts:

* **Degree of array** = একটি সংখ্যার সর্বোচ্চ frequency
* একাধিক সংখ্যা degree তৈরি করতে পারে
* তাদের first ও last index এর মধ্যে যেই subarray ছোট, সেটাই উত্তর

---

### 🔹 Steps:

1. Use 3 hash maps:

   * `freq[num]` → সংখ্যা কতবার এসেছে
   * `first[num]` → প্রথম কোথায় এসেছে
   * `last[num]` → শেষ কোথায় এসেছে

2. Loop দিয়ে সব info collect করো

3. Find `max_freq` = degree of array

4. যেসব সংখ্যার frequency == degree:

   * তাদের subarray length বের করো → `last[num] - first[num] + 1`
   * সবার মধ্যে যেটা smallest, সেটাই answer

---

### 🔹 Time Complexity:

**O(n)** – একবারই পুরো array traverse করো

---

এই ছোট version টা তুমি notebook বা cheat sheet-এ লিখে রাখতে পারো 📒✅
আরও চাইলে বলো!
*/


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        unordered_map<int, int> first_seen;
        unordered_map<int, int> last_seen;
        for( int i = 0; i < nums.size(); i++){
            hash_map[nums[i]]++;
            if(first_seen.find(nums[i]) == first_seen.end()){
                first_seen[nums[i]] = i;
            }
            last_seen[nums[i]] = i;
        }
        int max_freq = 0;
        for(auto& u:hash_map){
            if(u.second > max_freq){
                max_freq = u.second;
            }
        }
        int min_length = INT_MAX;
        for( auto& p:hash_map){
            if(p.second == max_freq){
                int len = last_seen[p.first] - first_seen[p.first] + 1;
                min_length = min(min_length, len);
            }
        }
        return min_length;
    }
};