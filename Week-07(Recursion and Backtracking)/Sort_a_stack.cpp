class Solution {
public:
    // Helper function to insert 'num' into a sorted stack
    void sortedInsert(stack<int> &st, int num){
        // Base case: if stack is empty OR top element is smaller than num
        if(st.empty() || (!st.empty() && st.top() < num)){
            st.push(num);  // Place num here
            return;
        }
        
        int n = st.top();  // Store the top element
        st.pop();          // Remove top element to recurse
        sortedInsert(st, num); // Recursively try to insert num
        st.push(n);        // Push the stored element back
    }

    // Main function to sort the stack
    void sortStack(stack<int> &st) {
        if(st.empty()) return;  // Base case: empty stack is already sorted
        
        int num = st.top();  // Take the top element
        st.pop();            // Remove it
        sortStack(st);       // Recursively sort the remaining stack
        sortedInsert(st, num); // Insert the removed element in sorted order
    }
};
 /*
Initial stack (top on left):

Top -> 5
       2
       9
      -7
       3

Step 1: sortStack called
- Pop 5 -> num = 5
- Recurse sortStack([2, 9, -7, 3])

Step 2: sortStack called
- Pop 2 -> num = 2
- Recurse sortStack([9, -7, 3])

Step 3: sortStack called
- Pop 9 -> num = 9
- Recurse sortStack([-7, 3])

Step 4: sortStack called
- Pop -7 -> num = -7
- Recurse sortStack([3])

Step 5: sortStack called
- Pop 3 -> num = 3
- Stack is empty -> return

Now we start inserting back using sortedInsert:

Insert 3:
- Stack empty -> push 3
Stack: [3]

Insert -7:
- Top = 3, -7 < 3 -> pop 3
- Stack empty -> push -7
- Push back 3
Stack: [3(top), -7]

Insert 9:
- Top = 3, 9 > 3 -> push 9
Stack: [9(top), 3, -7]

Insert 2:
- Top = 9, 2 < 9 -> pop 9
- Top = 3, 2 < 3 -> pop 3
- Top = -7, 2 > -7 -> push 2
- Push back 3, push back 9
Stack: [9(top), 3, 2, -7]

Insert 5:
- Top = 9, 5 < 9 -> pop 9
- Top = 3, 5 > 3 -> push 5
- Push back 9
Stack: [9(top), 5, 3, 2, -7]

Final sorted stack (descending order, top = largest):
Top -> 9
       5
       3
       2
      -7
*/
