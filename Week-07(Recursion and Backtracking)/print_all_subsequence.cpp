#include<bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Function to print all subsequences of the array
void print_sub(int idx, vector<int>& v, vector<int>& v1, int n){
    // Base case: if we have reached the end of the array
    if(idx == n){
        // Print the current subsequence stored in v1
        for(int i = 0; i < v1.size(); i++){
            cout << v1[i] << " ";
        }
        cout << endl; // Move to next line after printing one subsequence
        return; // Go back (backtrack)
    }

    // ✅ CHOICE 1: Take the current element
    v1.push_back(v[idx]);         // Include v[idx] in the current subsequence
    print_sub(idx + 1, v, v1, n); // Move to next index

    // Backtrack (remove the element we just took)
    v1.pop_back();

    // ✅ CHOICE 2: Do NOT take the current element
    print_sub(idx + 1, v, v1, n); // Move to next index without including v[idx]
}

int main(){
    int n; 
    cin >> n; // Input the size of the array

    vector<int> v; // This vector will store the input numbers

    // Take n numbers as input
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x); // Add each number to the vector
    }

    vector<int> v1; // This will store the current subsequence while building it
    print_sub(0, v, v1, n); // Start from index 0 and print all subsequences
}
