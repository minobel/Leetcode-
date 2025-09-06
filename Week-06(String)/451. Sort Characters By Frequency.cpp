class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Frequency map বানানো
        // প্রতিটি character এর frequency গণনা করার জন্য unordered_map ব্যবহার
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;   // প্রতিটি character count করা
        }

        // Step 2: Map থেকে vector-এ copy করা
        // কারন unordered_map sorted নয়, descending frequency অনুযায়ী sort করতে vector ব্যবহার করতে হবে
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Step 3: Vector sort করা
        // Lambda function দিয়ে descending frequency অনুযায়ী sort করা
        sort(vec.begin(), vec.end(),
             [](auto& x, auto& y) { return x.second > y.second; });

        // Step 4: Output string তৈরি করা
        // প্রতিটি character কে তার frequency অনুযায়ী string-এ যোগ করা
        string ans;
        for (auto& p : vec) {
            ans += string(p.second, p.first);  // p.first = character, p.second = frequency
        }

        // Step 5: Final string return করা
        return ans;
    }
};
