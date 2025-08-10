//Time Complexity: O(m·n)
//Space Complexity: O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // row এবং col এর সংখ্যা বের করা
        int row = matrix.size();
        int col = matrix[0].size();

        // কোন কোন row এবং column এ 0 আছে সেটা mark করার জন্য ভেক্টর বানানো
        vector<bool> mark_row(row, false);
        vector<bool> mark_col(col, false);

        // প্রথম ধাপ: matrix এ কোথায় 0 আছে সেটা খুঁজে বের করা
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    // i-th row এবং j-th column mark করা
                    mark_row[i] = true;
                    mark_col[j] = true;
                }
            }
        }

        // দ্বিতীয় ধাপ: mark করা row বা column থাকলে ঐ cell কে 0 করে দেওয়া
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // যদি row বা column mark করা থাকে তবে cell 0 হবে
                if (mark_row[i] || mark_col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


                                    //Now Optimized Code
                                   //Time Complexity: O(m·n)
                                  //Space Complexity: O(1)

                                  
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // Flag রাখবো: প্রথম row কি zero হবে?
        bool firstRowHasZero = false;
        // Flag রাখবো: প্রথম column কি zero হবে?
        bool firstColHasZero = false;

        // ধাপ 1: প্রথম row চেক করা
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // ধাপ 2: প্রথম column চেক করা
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // ধাপ 3: matrix-এর বাকী অংশে (প্রথম row/col বাদে) 0 খুঁজে বের করা
        // যেখানে 0 পাব, সেখানে প্রথম row ও প্রথম col-এ mark দিয়ে রাখা
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // column mark
                    matrix[i][0] = 0; // row mark
                }
            }
        }

        // ধাপ 4: row-এর mark দেখে পুরো row zero করা
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) { // এই row mark করা ছিল
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // ধাপ 5: column-এর mark দেখে পুরো column zero করা
        for (int j = 1; j < col; j++) {
            if (matrix[0][j] == 0) { // এই column mark করা ছিল
                for (int i = 1; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // ধাপ 6: যদি প্রথম row শুরুতেই zero হওয়ার কথা থাকে
        if (firstRowHasZero) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        // ধাপ 7: যদি প্রথম column শুরুতেই zero হওয়ার কথা থাকে
        if (firstColHasZero) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
