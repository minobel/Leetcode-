#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: ধরো প্রথম string টাকেই reference prefix হিসেবে নিলাম
        string prefix = strs[0];

        // Step 2: prefix এর প্রতিটা character এক এক করে চেক করবো
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i]; // reference string এর i-th character নিলাম

            // Step 3: বাকি string গুলোর i-th character এর সাথে মিলিয়ে দেখবো
            for(int j = 1; j < strs.size(); j++) {
                // যদি কোনো string এর length ছোট হয় বা mismatch হয়
                if(i >= strs[j].size() || strs[j][i] != c) {
                    // তাহলে i পর্যন্ত মিলেছে → ওটাই longest common prefix
                    return prefix.substr(0, i);
                }
            }
        }

        // Step 4: যদি পুরো prefix string টাই মিলে যায় → ওটাই common prefix
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl; // Output: "fl"
    return 0;
}


//NOW Optimized Code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: সব strings কে lexicographical order এ sort করলাম
        // Sorting এর পরে, সবচেয়ে ছোট এবং সবচেয়ে বড় string সবচেয়ে বেশি ভিন্ন হতে পারে
        sort(strs.begin(), strs.end());

        // Step 2: প্রথম string কে reference হিসেবে নিলাম
        string prefix = strs[0];

        // Step 3: শেষ string এর index নিলাম
        int j = strs.size() - 1;

        // Step 4: প্রথম এবং শেষ string এর character-by-character compare করা
        for(int i = 0; i < prefix.size(); i++){
            // যদি কোন character mismatch হয়, তখন prefix i পর্যন্ত থাকবে
            if(strs[j][i] != prefix[i]){
                return prefix.substr(0, i); // mismatch পাওয়া যায় → return LCP
            }
        }

        // Step 5: যদি পুরো first string last string এর সাথে match করে, ওটাই LCP
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    
    // Output দেখাবে "fl"
    cout << s.longestCommonPrefix(strs) << endl; 
    
    return 0;
}
