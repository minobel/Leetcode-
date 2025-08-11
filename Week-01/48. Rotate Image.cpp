//Time Complexity: O(r × c) → square হলে O(n²)

//Space Complexity: O(r × c) → square হলে O(n²)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();          // number of rows
        int c = matrix[0].size();       // number of columns
        
        // l = max(r, c)  → maximum dimension বের করা
        int l;
        if (r > c) l = r;
        else if (c > r) l = c;
        else l = r;

        int temp_l = l; // temp_l এখানে শেষ কলামের index ঠিক করতে ব্যবহার হচ্ছে
        
        // নতুন ম্যাট্রিক্স বানানো (rotated version রাখার জন্য)
        vector<vector<int>> new_matrix(c, vector<int>(r));

        // মূল ম্যাট্রিক্স থেকে নতুন ম্যাট্রিক্সে element কপি করা
        // এমনভাবে কপি করা হচ্ছে যাতে rotate (90° clockwise) হয়
        for (int i = 0; i < r; i++) {           // প্রতিটি row
            for (int j = 0; j < c; j++) {       // প্রতিটি column
                if (temp_l > 0) { // index negative না হওয়ার জন্য check
                    // new_matrix এর j-th row এর (temp_l - 1)-th column এ value বসানো
                    new_matrix[j][temp_l - 1] = matrix[i][j];
                }
            }
            temp_l--; // পরের row এর জন্য target column index কমানো
        }

        // নতুন rotated ম্যাট্রিক্সকে মূল matrix এ assign করা
        matrix = new_matrix;
    }
};

 // Time Complexity: O(n²)

// Space Complexity: O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // ম্যাট্রিক্স square, তাই row = col = n

        // Step 1: Transpose the matrix
        // অর্থাৎ row ↔ column swap করা (a[i][j] → a[j][i])
        // শুধু upper triangle এর element গুলোর সাথে lower triangle swap করলেই হয়
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // Transpose এর পর row reverse করলে 90° clockwise rotation হয়ে যায়
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
