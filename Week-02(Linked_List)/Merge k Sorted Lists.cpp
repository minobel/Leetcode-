//T.C. - O(Nlog(K))
//S.C. - O(log(K))
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
ListNode* MergeLists( ListNode* List1, ListNode* List2 ){
    ListNode* dHead = new ListNode(0);
    ListNode* Temp = dHead;
    while( List1 != NULL && List2 != NULL ){
        if( List1 -> val <= List2 -> val ){
        Temp -> next = List1;
        Temp = List1;
        List1 = List1 -> next;
        }
        else {
        Temp -> next = List2;
        Temp = List2;
        List2 = List2 -> next;
        }
    }
    if( List1 != NULL ){
        Temp -> next = List1;
    }
    else Temp -> next = List2;
    return dHead -> next;
}
ListNode* merger(int L, int H, vector < ListNode* > &Lists){
    if( L > H ) return nullptr;
    if( L == H ) return Lists[L];
    int mid = ( L + H ) / 2;
    ListNode* Left = merger(L, mid, Lists );
    ListNode* Right = merger(mid + 1, H, Lists);
    return MergeLists( Left , Right );
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merger(0, lists.size() - 1, lists);
    }
};
