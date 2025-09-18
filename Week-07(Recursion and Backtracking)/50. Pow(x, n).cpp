//Binary Expension Method
class Solution {
public:
    double myPow(double x, int n) {
        bool neg = false;          // Flag to check if power is negative
        long long N = (long long)n; // Convert n to long long to avoid overflow for INT_MIN
        
        // Handle negative power
        if(N < 0) {
            neg = true;   // Mark that power was negative
            N = -1 * N;   // Make power positive
        }
        
        double ans = 1; // Variable to store the final answer
        
        // Iterative Binary Exponentiation
        while(N > 0){
            if(N % 2 == 1){       // If power is odd
                ans = ans * x;   // Multiply current result by base
                N = N - 1;       // Reduce power by 1 (make it even)
            }
            else{
                x = x * x;       // Square the base
                N = N / 2;       // Halve the power
            }
        }
        
        // If the original power was negative, return reciprocal
        if(neg) return 1.0 / ans;
        
        // Otherwise, return the result normally
        return ans;
    }
};

//Recursive Method
class Solution {
public:
    // Recursive helper function to calculate x^n
    double solve(double x, long long n){
        if(n == 0) 
            return 1;  // Base case: any number to the power 0 is 1

        if(n < 0) 
            return solve(1/x, -n);  
            // If power is negative, take reciprocal of x and make power positive

        if(n % 2 == 0) 
            return solve(x * x, n / 2);  
            // If power is even:
            // x^n = (x*x)^(n/2)
            // This reduces the problem size by half each time

        else 
            return x * solve(x * x, (n - 1)/2);  
            // If power is odd:
            // x^n = x * (x*x)^((n-1)/2)
            // We remove one x and then reduce problem to even power
    }

    // Main function called by user
    double myPow(double x, int n) {
        // Cast n to long long to handle large negative numbers safely
        return solve(x, (long long)n);
    }
};
