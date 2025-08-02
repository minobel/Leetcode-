// Straight Forward Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for( int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zeros++;
            else if(nums[i] == 1) ones++;
            else twos++;
        }
        for( int i = 0; i < zeros; i++){
            nums[i] = 0;
        }
        for( int i = zeros; i < (zeros + ones); i++){
            nums[i] = 1;
        }
        for( int i = (zeros + ones); i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};

//Optimal Solution using Dutch National Flag Algorithm
/*কখন ব্যবহার করব Dutch National Flag Algorithm?
যখন তোমার কাছে একটা array থাকবে যেটায় শুধু ৩ ধরনের এলিমেন্ট আছে (যেমন: 0, 1, 2) এবং তোমাকে ওই array-টা এই ৩ ধরনের এলিমেন্টকে একটা নির্দিষ্ট ক্রমে সাজাতে হবে — তখন এই অ্যালগরিদম খুব কাজে লাগে।

কীভাবে কাজ করে:
তিনটা pointer বা index রাখবে:

low → ০ গুলোর জন্য পরের জায়গা

mid → বর্তমানে যে element দেখছ

high → ২ গুলোর জন্য পরের জায়গা

একবার array-র মধ্য দিয়ে mid pointer চলে যাবে, আর প্রতিবার:

যদি nums[mid] == 0 হয় → nums[low] এর সাথে swap করো, low++, mid++

যদি nums[mid] == 1 হয় → mid++ (কিছুই swap করতে হবে না)

যদি nums[mid] == 2 হয় → nums[mid] এবং nums[high] swap করো, high-- (কিন্তু mid একই থাকবে কারণ নতুন value দেখে নিতে হবে)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, m = 0;
        while(m <= h){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};