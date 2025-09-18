//Binary Exponentiation
class Solution {
public:
    const long long MOD = 1e9+7; // Define the modulo value

    // Iterative function to calculate (base^power) % MOD
    long long mypow(long long base, long long power){
        long long ans = 1; // Initialize result
        
        while(power > 0){
            if(power % 2 == 1){
                // If power is odd, multiply current result by base
                ans = (ans * base) % MOD; // Take modulo to avoid overflow
                power -= 1; // Reduce power by 1 to make it even
            }
            else{
                // If power is even, square the base and halve the power
                base = (base * base) % MOD; // Square the base safely under modulo
                power = power / 2;           // Halve the power
            }
        }
        
        return ans; // Return (base^power) % MOD
    }

    // Main function to count good numbers
    int countGoodNumbers(long long n) {
        // Count of digits at even positions (0-indexed)
        long long even_pos_count = (n + 1)/2; // ceil(n/2)
        // Count of digits at odd positions
        long long odd_pos_count = n / 2;      // floor(n/2)

        // Calculate 5^(even_pos_count) % MOD
        long long even_sum = mypow(5, even_pos_count);
        // Calculate 4^(odd_pos_count) % MOD
        long long odd_sum  = mypow(4, odd_pos_count);

        // Multiply both results and take modulo
        return (even_sum * odd_sum) % MOD;
    }
};

//Recursive Method
class Solution {
public:
    const long long MOD = 1e9+7; // Define modulo value

    // Recursive function to calculate (base^power) % MOD
    long long mypow(long long base, long long power){
        long long ans = 1;  // Initialize result
        
        if(power == 0) 
            return 1;  // Base case: any number to the power 0 is 1
        
        if(power % 2 == 0) 
            // If power is even: use formula (x^n) = (x*x)^(n/2)
            return mypow((base * base) % MOD, power / 2);
        else 
            // If power is odd: x^n = x * (x*x)^((n-1)/2)
            return (base * mypow((base * base) % MOD, (power - 1)/2)) % MOD;
            // Multiply base and take modulo to prevent overflow
    }

    // Main function to count good numbers of length n
    int countGoodNumbers(long long n) {
        // Count of digits at even positions (0-indexed)
        long long even_pos_count = (n + 1)/2; // ceil(n/2)
        // Count of digits at odd positions
        long long odd_pos_count = n / 2;      // floor(n/2)

        // Calculate 5^(even_pos_count) % MOD
        long long even_sum = mypow(5, even_pos_count);
        // Calculate 4^(odd_pos_count) % MOD
        long long odd_sum  = mypow(4, odd_pos_count);

        // Multiply both results and take modulo
        return (even_sum * odd_sum) % MOD;
    }
};
