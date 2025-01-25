//T.C. - O(max(N,M)) Here N = Size of L1 & M = Size of L2
//S.C. = O(max(N,M))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dHead = new ListNode(-1);
            ListNode* curr = dHead;
            int carry = 0;
            while( l1 != NULL || l2 != NULL ){
                int sum = 0;
                if( l1 ) sum = sum + l1 -> val;
                if( l2 ) sum = sum + l2 -> val;
                sum = sum + carry;
                ListNode* newNode = new ListNode( sum % 10 );
                carry = sum / 10;
                curr -> next = newNode;
                curr = curr -> next;
                if( l1 ) l1 = l1 -> next;
                if( l2 ) l2 = l2 -> next;
            }
            if( carry ) {
                ListNode* newNode = new ListNode( carry );
                curr -> next = newNode;
            }
            return dHead -> next;
}
};
